#include "cell.hpp"


#include <sstream>

int main(int argc, char **argv) {

/*-------------------------Checking command line section-----------------------------*/
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
/*------------------------Getting height and lenght of matrix------------------------*/
	std::ifstream input;
	input.open(in_filename.c_str());
	int linhas, colunas;
	input >> linhas >> colunas;
	input.close();
/*-----------------------------------------------------------------------------------*/

	std::ifstream ifs;

	Cell cel(linhas, colunas);
	cel.set_alive(in_filename, ifs);
	cel.print();

	Cell sel(linhas, colunas);
	sel.GenBackup(cel);
	sel.future(cel);
	sel.GenCompare(cel);
	sel.print();

	ifs.close();

	return 0;
}
