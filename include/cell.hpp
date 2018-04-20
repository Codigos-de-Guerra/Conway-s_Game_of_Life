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
};

#endif
