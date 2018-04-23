/* Authors: Daniel Guerra and Oziel Alves */

#include "cell.hpp"
#include <sstream>

int main(int argc, char **argv) {

/**---------------------Checking command line section------------------------*/
	if(argc != 2) {
		std::cerr << "Invalid command line input!\n";
		return -1;
	}

	std::istringstream ss(argv[1]);
	std::string in_filename;
	if(!(ss >> in_filename)) {
		std::cerr << "Not a valid string\n";
		return -2;
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
	long int counter;

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

		if(estavel == true || extinto == true) {
			break;
		}
		
		char answer; // To determinate if user wants to print
		std::cout<<"Do you wish to keep printing?\nPress y (YES) or n (NO):\n";
		std::cin >> answer;
		
		if(answer == 'n' or answer == 'N') {
			break;
		}
		temp.print(ofs, counter);

		sel = temp;

		/*Como no início eu sempre crio 'temp' a partir de sel, e sel é sempre
		 a mesma coisa, então o temp criado também sempre será a mesma coisa
		Precisamos atualizar sel para receber esse temp que acabamos de criar,
		para então na próxima iteração do while o 'temp' receber esse novo sel,
		e assim estaremos sempre gerando um novo 'temp' para printar.
		Resumindo, no final do corpo do while precisamos de algo assim:*/

		//sel = temp;

	/* Tente fazer isso Oziel-san */

	}
	
	return 0;
}
