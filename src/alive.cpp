#include "alive.hpp"
#include "cell.hpp"

/*void Cell::set_alive(std::string file, std::ifstream& ifs_) {
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

int Cell::alive_counting(int ypos, int xpos, Cell& rhs) {

	// Variable to be incremented when current cell has a living neighbor.
	int count = 0;
	int inicio, final;
/*---------------------------------------------------------------------------*/
	/*
	This section establishes from where, or until where to check the xpos positions.
	Therefore, avoid the error of checking off-border values.
	*/
	
/*	//First, I considerate it being on the left border.
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
/*	if(ypos > 0) {
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
/*	if(ypos < rhs.lin - 1) {
		for( int i=inicio; i < final; i++) {
			if(rhs.ptr_M[ypos+1][i] == rhs.live_cell) {
				count++;
			}
		}
	}

	return count;
}
*/