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
  int m_col;                // Matrix
  int m_lin;
  // To know if the cell is alive or dead
  bool status;
  
  public:
  Cell( int, int );
  ~Cell(int, int );
  Cell();
  ~Cell();
  
  int alive_counting( int, int, Cell& );
  
  void print ( void );
  
  
  
};

#endif
