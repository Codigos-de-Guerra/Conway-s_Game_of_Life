/*!
 * C++ implementation of Conway's game of life
 * @date April, 19th.
 */

#include <iostream>
#include <vector>


/// Define X and Y as the width and the hight
static void nextGeneration(){



/// Finding neighbours alive
	int aliveNeighbours = 0;
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			aliveNeighbours += grid[l + i,m + j];
		}
	}
}	 
