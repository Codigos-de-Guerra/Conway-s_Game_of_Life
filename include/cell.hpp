/*!
* \On this code we define the Cell class which will contain some of the game like the board parameters and the cell status.
* 
* @date April, 19th.
*/

#ifndef CELL_H_
#define CELL_H_

#include <iostream>

class Cell{
  private:
    char **ptr_M;
    int col;
    int lin;
    char live_cell;
    char dead_cell;

  public:
    /** Common constructor. Allocates necessary usage space for matrix. Also initializes some private class variables. */
    Cell(int height, int lenght);

/*------------------------Respectively, it's destructor.------------------ */
    // Freeing previous allocated space.

    /// Não sei se vai dar bug deixar o destrutor *
    ~Cell() {
      for(int i=0; i < lin; i++) {
        delete [] ptr_M[i];
      }
      delete [] ptr_M;
    }  
};

#endif
