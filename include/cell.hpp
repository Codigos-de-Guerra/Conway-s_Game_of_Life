/*!
* \On this code we define the Cell class which will contain some of the game like the board parameters and the cell status.
* 
* @date April, 19th.
*/

#ifndef CELL_HPP_
#define CELL_HPP_

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

class Cell{
  
  //private:
  public:
    char **ptr_M;
    int col;
    int lin;
    char live_cell;
    char dead_cell;

  //public:
  /** Common constructor. Allocates necessary usage space for matrix. 
      Also initializes some private class variables. */
    Cell( int , int );

    int alive_counting( int, int, Cell& ); //Testando

    void set_alive( std::string, std::ifstream& ); //Testando

    void future( Cell& a ); // Testando

    void print( void ) const; // Testando


/*------------------------Respectively, it's destructor.------------------ */
  
  // Freeing previous allocated space.
    ~Cell();
}; 
#endif
