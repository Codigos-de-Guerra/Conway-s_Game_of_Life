#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <sstream>

class Cell {
	private:
		char **ptr_M;
		int col;
		int lin;
		char live_cell;
		char dead_cell;

	public:
		/* Common constructor. Allocates necessary usage space for matrix. Also initializes some private class variables. */
		Cell(int height, int lenght) {
			ptr_M = new char*[height];
			for(int i=0; i < height; i++) {
				*(ptr_M+i) = new char[lenght];
			}

			lin = height;
			col = lenght;
		}

/*------------------------Respectively, it's destructor.------------------ */
		// Freeing previous allocated space.
		~Cell() {
			for(int i=0; i < lin; i++) {
				delete [] ptr_M[i];
			}
			delete [] ptr_M;
		}
		
/* ----------------------------------------------------------------------------------*/
		
		void set_alive(std::string file, std::ifstream& ifs_) {
			std::cout << "Constructor ativado!\n";
			int nLin, nCol;
			char vivo, caracter;

			ifs_.open(file.c_str());
			ifs_ >> nLin >> nCol;
			ifs_ >> vivo;

			for(int i=0; i < nLin; i++) {
				for(int j=0; j < nCol; j++) {
					ifs_ >> caracter;
					ptr_M[i][j] = caracter;
				}
			}

			live_cell = vivo;
			dead_cell = '_';

			ifs_.close();
		}

		int alive_counting(int ypos, int xpos, Cell& rhs) {

			// Variable to be incremented when current cell has a living neighbor.
			int count = 0;
			int inicio, final;
		/*--------------------------------------------------------------------------------------------------------------*/
			/*
				This section establishes from where, or until where to check the xpos positions.
				Therefore, avoid the error of checking off-border values.
			*/
			//First, I considerate it being on the left border.
			if(xpos == 0) {
				inicio = xpos;
			}
			else {
				inicio = xpos-1;
			}

			//Then, I considerate it being on the right border.
			if(xpos == rhs.col - 1) {
				final = xpos+1;
			}
			else {
				final = xpos+2;
			}

		/*--------------------------------------------------------------------------------------------------------------------*/

			/*
			On this section, my counting for alive cells surrounding the moment cell takes action.
			I will also check ypos positions for bordes.
			*/

			/* Only calculates when not at upper border. */
			if(ypos > 0) {
				for( int i=inicio; i < final; i++) {
					if(rhs.ptr_M[ypos-1][i] == rhs.live_cell) {
						count++;
					}
				}
			}
			for( int i=inicio; i < final; i++) {
				//std::cout << rhs.ptr_M[ypos][i] << "\n";
				//bool aa = (rhs.ptr_M[ypos][i] == rhs.live_cell);

				//std::cout << rhs.live_cell << "\n";

				//std::cout << aa << "\n";
				if(rhs.ptr_M[ypos][i] == rhs.live_cell) {
					if( i == xpos) continue; // This would check the cell itself, which i do not want to happen.
					count++;
				}
			}

			/*Only calculates if i am not looking at the lower border. */
			if(ypos < rhs.lin - 1) {
				for( int i=inicio; i < final; i++) {
					if(rhs.ptr_M[ypos+1][i] == rhs.live_cell) {
						count++;
					}
				}
			}

			return count;
		}

		//Function to print on terminal current display of cells.
		void print (void) const {
			std::cout << "Colunas = " << col << "Linhas = " << lin << "\n";
			for(auto i=0; i < lin; i++) {
				for(auto j=0; j < col; j++) {
					std::cout << ptr_M[i][j];
				}
				std::cout << "\n";
			}
		}

		void future (Cell& a) {
			live_cell = a.live_cell;
			dead_cell = a.dead_cell;

			//Here, I check if the previous found cells follows de rules to survive and to be bornt.
			for(int i=0; i < a.lin; i++) {
				for(int j=0; j < a.col; j++) {

					//------------Prints to help undestand what is going on.
					//std::cout << "Started checking: " << i << " " << j << "\n\n";

					//Function to determine how many alive neighbors a specific cell has.
					int living_neighbors = alive_counting(i, j, a);

					//------------Prints to help undestand what is going on.
					//std::cout << "Vizinhos vivos: " << living_neighbors << "\n";

					/*
					If current cell is alive, then it must have 2 or 3 living neighbors to survive.
					Otherwise, it dies.
					*/
					if(a.ptr_M[i][j] == a.live_cell) {
						if(living_neighbors == 2 || living_neighbors == 3) {
							ptr_M[i][j] = live_cell;
						}
						else {
							ptr_M[i][j] = dead_cell;
						}
					}

					/*
					If current cell is dead, then it must have exactly 3 neighbors in order to be bornt.
					Otherwise, it stays dead.
					*/
					else {
						if(living_neighbors == 3) {
							ptr_M[i][j] = a.live_cell;
						}
						else {
							ptr_M[i][j] = dead_cell;
						}
					}

					//------------Prints to help undestand what is going on.
					//std::cout << "Finished checking: " << i << " " << j << "\n\n";
				}
			}
		}
};
int main(int argc, char **argv) {

/*-------------------Checking command line section----------------------------*/
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
/*--------------------------Getting height and lenght of matrix------------------*/
	std::ifstream input;
	input.open(in_filename.c_str());
	int linhas, colunas;
	input >> linhas >> colunas;
	input.close();
/*-------------------------------------------------------------------------------*/

	std::ifstream ifs;

	Cell cel(linhas, colunas);
	cel.set_alive(in_filename, ifs);
	cel.print();

	Cell sel(linhas, colunas);
	sel.future(cel);
	sel.print();

	ifs.close();

	return 0;
}
