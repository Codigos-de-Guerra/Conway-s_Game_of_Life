/* Authors: Daniel Guerra and Oziel Alves */

#include "cell.hpp"
#include <sstream>
//q
int main(int argc, char **argv) {

/**---------------------Checking command line section------------------------*/
	if(argc != 4) {
		std::cerr << "Invalid command line input!\n";
		return -1;
	}
	
	/* Through command line, client is going to define if wants to keep
	generating until stable or extinct state is reached
	*/
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
	Cell start_cell(linhas, colunas);
	start_cell.set_alive(in_filename, ifs);	
	start_cell.print(ofs, counter);

/**---------------Making next state from the first cell state----------------*/
	Cell perfect_cell(linhas, colunas);
	perfect_cell.GenBackup(start_cell);
	perfect_cell.future(start_cell);
	perfect_cell.GenCompare();
	perfect_cell.print(ofs, counter);

/**----Now, we start asking if user wants to keep printing next states-------*/

/** Also, if the cell state is extinct or already stablized, we won't print at 
 * all */
	
	while( 1 > 0) {
		
		Cell temp_cell(linhas, colunas);
		temp_cell.GenBackup(perfect_cell);
		temp_cell.future(perfect_cell);
		temp_cell.GenCompare();
		
		bool estavel = temp_cell.st();
		bool extinto = temp_cell.ex();

		if(estavel == true && extinto == false) {
			temp_cell.print(ofs, counter);

			std::cout << ">>> Generation " << counter-1 << " is already stabilized!";
			std::cout << " Both " << counter-1 << " and " << counter << " generations are equal.\n";
			std::cout << ">>> No need to keep generating. \n";

			ofs << ">>> Generation " << counter-1 << " is already stabilized!";
			ofs << " Both " << counter-1 << " and " << counter << " generations are equal.\n";
			ofs << ">>> No need to keep generating. \n";

			break;
		}
		else if(estavel == false && extinto == true) {
			temp_cell.print(ofs, counter);
			std::cout << ">>> Generation " << counter << " is extinct!\n";
			std::cout << ">>> Entire body cell is dead! Won't generate more.\n";

			ofs << ">>> Generation " << counter << " is extinct!\n";
			ofs << ">>> Entire body cell is dead! Won't generate more.\n";
			break;
		}
		if(until == "-u") {
			temp_cell.print(ofs, counter);
			perfect_cell = temp_cell;
		}
		else if(until == "-yn") {		
			char answer; // To determinate if user wants to print
			std::cout<<"Do you wish to keep printing? Press y for YES or n for NO: ";
			std::cin >> answer;
		
			if(answer == 'n' or answer == 'N') {
				break;
			}
			
			temp_cell.print(ofs, counter);
			perfect_cell = temp_cell;
		}
	}

	ofs.close();
	return 0;
}
