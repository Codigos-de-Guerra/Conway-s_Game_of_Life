/* Authors: Daniel Guerra and Oziel Alves */

#include "cell.hpp"
#include <sstream>

int main(int argc, char **argv) {

/**---------------------Checking command line section------------------------*/
	if(argc != 4) {
		std::cerr << "Invalid command line input!\n";
		return -1;
	}
	
	// Through command line, client is going to define if wants to keep generating until stable or extinct state is reached
	std::istringstream as(argv[1]);
	std::string until;
	if(!(as >> until)) {
		std::cerr << "Not a valid string\n";
		return -2;
	}
	if(until != "-u" && until != "-yn") {
		std::cerr << "Not a valid command line argument!\n";
		return -3;
	}

	//Through command line, user is defining the data input file
	std::istringstream bs(argv[2]);
	std::string in_filename;
	if(!(bs >> in_filename)) {
		std::cerr << "Not a valid string\n";
		return -4;
	}
	
	// Through command line, user is defining the data output file
	std::istringstream cs(argv[3]);
	std::string out_filename;
	if(!(cs >> out_filename)) {
		std::cerr << "Not a valid string\n";
		return -5;
	}

/**-------------------Getting height and lenght of matrix--------------------*/
	std::ifstream input;
	input.open(in_filename.c_str());
	int linhas, colunas;
	input >> linhas >> colunas;
	input.close();

/**--------------------------------------------------------------------------*/
	std::ifstream ifs;
	std::ofstream ofs;
	ofs.open(out_filename.c_str());
	long int counter = 0;			//This will keep track of generation number.

/**------------------------Creates first cell state--------------------------*/
	Cell cel(linhas, colunas);
	cel.set_alive(in_filename, ifs);	
	cel.print(ofs, counter);

/**---------------Making next state from the first cell state----------------*/
	Cell sel(linhas, colunas);
	sel.GenBackup(cel);
	sel.future(cel);
	sel.GenCompare();
	sel.print(ofs, counter);

/**----Now, we start asking if user wants to keep printing next states-------*/

/** Also, if the cell state is extinct or already stablized, we won't print at 
 * all */
	
	while( 1 > 0) {
		
		Cell temp(linhas, colunas);
		temp.GenBackup(sel);
		temp.future(sel);
		temp.GenCompare();
		
		bool estavel = temp.st();
		bool extinto = temp.ex();

		if(estavel == true && extinto == false) {
			std::cout << "Previously found generation is already stabilized! Won't generate more.\n";
			//ofs << "Previously found generation is already stabilized! Won't generate more.\n";
			break;
		}
		else if(estavel == false && extinto == true) {
			std::cout << "Next generation would be extinct! Won't generate more.\n";
			//ofs << "Next generation would be extinct! Won't generate more.\n";
			break;
		}
		else if(estavel == true && extinto == true) {
			std::cout << "Previously generation is already stabilized and in it's final alive form! Won't generate more.\n";
			//ofs << "Previously generation is already stabilized and in it's final alive form! Won't generate more.\n";
			break;
		}

		if(until == "-u") {
			temp.print(ofs, counter);
			sel = temp;
		}
		else if(until == "-yn") {		
			char answer; // To determinate if user wants to print
			std::cout<<"Do you wish to keep printing? Press y for YES or n for NO: ";
			std::cin >> answer;
		
			if(answer == 'n' or answer == 'N') {
				break;
			}
			
			temp.print(ofs, counter);
			sel = temp;
		}
	}
	ofs.close();
	return 0;
}
