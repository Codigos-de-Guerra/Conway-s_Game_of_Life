#include "future.h"

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
				else{
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