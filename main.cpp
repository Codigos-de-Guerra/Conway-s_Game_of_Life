#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

class Cell {
	
	private:
		char **ptr_M;
		int col;
		int lin;
		char alive;
	public:
		//Constructor to allocate and initialize individual pointers.
		//Representation of each of my cells.
		Cell(std::string file, std::ifstream& ifs_) {
			std::cout << "Elemento construido\n";
			int nLin,nCol;
			char vivo, caracter;

			ifs_.open(file.c_str());
			ifs_ >> nLin >> nCol;
			ifs_ >> vivo;

			ptr_M = new char*[nLin];
			for(int i=0; i < nLin; i++) {
				*(ptr_M+i) = new char[nCol];
				for(auto j=0; j < nCol; j++) {
					ifs_ >> caracter;
					ptr_M[i][j] = caracter;
				}
			
			}

			lin = nLin;
			col = nCol;
		}

		//Destructor. Freeing allocated space.
		~Cell() {
			std::cout << "Elemento destruido\n";

			for(int i(0u); i < lin; i++) {
				delete [] ptr_M[i];
			}
			delete [] ptr_M;
		}

		//Função teste para referencia de classes
		void print (void) const {
			std::cout << "Colunas = " << col << "Linhas = " << lin << "\n";
		}
};

int main(int argc, char **argv) {
	if(argc != 2) {
		std::cerr << "Invalid command line input!\n";
		return -1;
	}
	std::istringstream ss(argv[1]);
	std::string in_filename;
	if(!(std::ss >> in_filename)) {
		std::cerr << "Not a valid string\n";
		return -2;
	} 

	std::ifstream ifs;
		
	Cell cel(in_filename, ifs);
	cel.print();

	return 0;
}
