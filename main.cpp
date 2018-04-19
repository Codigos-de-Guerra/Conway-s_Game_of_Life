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
		/* Common constructor, with only, and just, allocation of my matrix of data.
-----------------------Not sure if going to use it-----------------------------
		Cell(int height, int lenght) {
			ptr_M = new char[height];
			for(int i=0; i < height; i++) {
				*(ptr_M+i) = new char[lenght];
			}
		} 
		*/
		/*
----------------Respectively, it's common destructor.------------------
		~Cell(int height, int lenght) {
			for(int i=0; i < height; i++) {
				delete [] ptr_M[i];
			}
			delete [] ptr_M;
		}
		
--------------------------------------------------------------------------------
		*/

		//Constructor to allocate and initialize individual pointers.
		//Representation of each of my cells.
		Cell(std::string file, std::ifstream& ifs_) {
			std::cout << "Instancia construida\n";
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

			ifs_.close();
		}

		//Destructor. Freeing allocated space.
		~Cell() {
			std::cout << "Instancia destruida\n";

			for(int i(0u); i < lin; i++) {
				delete [] ptr_M[i];
			}
			delete [] ptr_M;
		}

		int alive_counting(int ypos, int xpos, Cell& rhs) {
			int count = 0;
			for(int i=xpos-1; i < xpos+2; i++) {
				if(rhs->ptr_M[ypos-1][i] == rhs.live_cell) {
					count++;
				}
			}
			for(int i=xpos-1; i < xpos+2; i++) {
				if(rhs->ptr_M[ypos][i] == rhs.live_cell) {
					if( i == xpos) continue;
					count++;
				}
			}
			for(int i=xpos-1; i < xpos+2; i++) {
				if(rhs->ptr_M[ypos+1][i] == rhs.live_cell) {
					count++;
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

		Cell(Cell& a) {
			for(int i=0; i < a.lin; i++) {
				for(int j=0; j < a.col; j++) {
					int live_neighbors = alive_counting(i, j, a);
					if(a->ptr_M[i][j] == a.live_cell) {
						if(live_neighbors < 2 || live_neighbors > 3) {
							this->ptr_M[i][j] = a.dead_cell;
						}
					}
					else {
						if(live_neighbors == 3) {
							this->ptr_M[i][j] = a.live_cell;
						}
					}
				}
			}
		}
};

int alive_counting(int ypos, int xpos, Cell& rhs) {
	int count = 0;
/*--------------------------------------------------------------------------------------------------------------*/
	/*
		This section establishes from where, or until where to check the xpos positions.
		Therefore, avoid the error of checking off-border values.
	*/
	//First, I considerate it being on the left border.
	if(xpos == 0) {
		int inicio = xpos;
	}
	else {
		int inicio = xpos-1;
	}

	//Then, I considerate it being on the right border.
	if(xpos == rhs.col - 1) {
		int final = xpos+1;
	}
	else {
		int final = xpos+2;
	}
/*--------------------------------------------------------------------------------------------------------------------*/
	/*
	On this section, my counting for alive cells surrounding the moment cell takes action.
	I will also check ypos positions for bordes.
	*/

	/* Only calculates when not at upper border. */
	if(ypos > 0) {
		for( int i=inicio; i < final; i++) {
			if(rhs->ptr_M[ypos-1][i] == rhs.live_cell) {
				count++;
			}
		}
	}
	for( int i=inicio; i < final; i++) {
		if(rhs->ptr_M[ypos][i] == rhs.live_cell) {
			if( i == xpos) continue;
			count++;
		}
	}

	/*Only calculates if i am not looking at the lower border. */
	if(ypos < rhs.lin - 1) {
		for( int i=inicio; i < final; i++) {
			if(rhs->ptr_M[ypos+1][i] == rhs.live_cell) {
				count++;
			}
		}
	}
	return count;
}


int main(int argc, char **argv) {
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

	std::ifstream ifs;
		
	Cell cel(in_filename, ifs);
	cel.print();
	
	Cell fut(cel);
	fut.print();

	

	return 0;
}
