#include "cell.hpp"

Cell::Cell(int height, int lenght) {
    ptr_M = new char*[height];
    for(int i=0; i < height; i++) {
      *(ptr_M+i) = new char[lenght];
    }
    lin = height;
    col = lenght;
}

Cell::~Cell () {
	std::cout << "Destructor ativado!\n";
    for(int i=0; i < lin; i++) {
		delete [] ptr_M[i];
		delete [] ptr_M_bkp[i];
    }
    delete [] ptr_M;
	delete [] ptr_M_bkp;
}

void Cell::set_alive (std::string file, std::ifstream& ifs_) {
    std::cout << "Constructor ativado!\n";
    int nLin, nCol;
    char vivo, caracter;

    ifs_.open(file.c_str());
	ifs_ >> nLin >> nCol;
	ifs_ >> vivo;
	live_cell = vivo;

	for(int i=0; i < nLin; i++) {
		for(int j=0; j < nCol; j++) {
			ifs_ >> caracter;
			ptr_M[i][j] = caracter;
		}
	}
	
	int count = 0; //Variable for breaking purposes
	for(int i=0; i < nLin; i++) {
		for(int j=0; j < nCol; j++) {
			if(ptr_M[i][j] != live_cell) {
				dead_cell = ptr_M[i][j];
				count++;
				break;
			}
		}
		if(count == 1) break;
		std::cout << "oi\n";
	}

	ifs_.close();
}

int Cell::alive_counting (int ypos, int xpos, Cell& rhs) {
	// Variable to be incremented when current cell has a living neighbor.
	int count = 0;

	int inicio, final;
/*---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------*/

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

void Cell::GenBackup (Cell& a){

	// Making a full backup of the matrix
	for(int i(0); i < a.lin; i++) {
		for(int j(0); j < a.col; j++) {
			ptr_M_bkp[i][j] = a.ptr_M[i][j]; 
		}
	}
}

void Cell::future (Cell& a) {
  
	live_cell = a.live_cell;
	dead_cell = a.dead_cell;

	//Here, I check if the previous found cells follows de rules to survive and to be bornt.
	for(int i=0; i < a.lin; i++) {
		for(int j=0; j < a.col; j++) {
			//------------Prints to help undestand what is going on.
			//std::cout << "Started checking: " << i << " " << j << "\n\n";

			//Function to determine how many alive neighbors a specific cell has.
			int living_neighbors = Cell::alive_counting(i, j, a);

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
				else{
					ptr_M[i][j] = dead_cell;
				}
			}
			//------------Prints to help undestand what is going on.
			//std::cout << "Finished checking: " << i << " " << j << "\n\n";
		}
	}
}

/** This function will tell me if the board is stable and/or if all the cells are
	dead.*/ 
void Cell::GenCompare ( void ) {

	bool flag_ex = true;//Flag that determinates if extincty has been confirmed.
	bool flag_st = true;//Flag that sees if stability has been confirmed.

	//As standart, we will consider both states to be true.
	stable = true;
	extinct = true;

	/*
	Checks if previous cell state is equal to actual cell state.
	Equivalent to a stable function.
	*/
	for(int i(0); i < lin; i++) {
    	for(int j(0); j < col; j++) {
    		if(ptr_M_bkp[i][j] != ptr_M[i][j]) {
				stable = false;
				flag_st = false;
				break;
			}
		}
		if(flag_st == false) break;
	}

	/*
	Checks if actual cell state represents only dead cells.
	Equivalent to a extinct function.
	*/
	for(int i(0); i < lin; i++) {
		for(int j(0); j < col; j++) {
			if(ptr_M[i][j] != dead_cell) {
				extinct = false;
				flag_ex = false;
				break;
			}
		}
		if(flag_ex == false) break;
	}

	//if( flag == true ) // [-> The whole board is dead <-]
}		

void Cell::print (std::ofstream& ofs_) const {
	ofs_.open("data/saida.txt", std::ofstream::app);

	for(auto i=0; i < lin; i++) {
		for(auto j=0; j < col; j++) {
			std::cout << ptr_M[i][j];
			ofs_ << ptr_M[i][j];
		}
		std::cout << "\n";
		ofs_ << "\n";
	}
	std::cout << "\n\n";
	ofs_ << "\n\n";
	ofs_.close();
}

bool Cell::st( void ) {
	bool ab = stable;
	return ab;
}

bool Cell::ex( void ) {
	bool ba = extinct;
	return ba;
}

