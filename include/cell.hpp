/*!
* \On this code we define the Cell class which will contain some of the game like the board parameters and the cell status.
* 
* @date April, 19th.
*/

#ifndef CELL_H_
#define CELL_H_

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>


class Cell{
  private:
    char **ptr_M, **ptr_M_bkp;
    int lin, col;
    char live_cell, dead_cell;
	bool stable, extinct;

  public:
    /** Common constructor. Allocates necessary usage space for matrix. 
        Also initializes some private class variables. */
    Cell(int height, int lenght);
/*------------------------Respectively, it's destructor.-------------------------- */
    // Freeing previous allocated space.
    ~Cell(void);
    void set_alive(std::string file, std::ifstream& ifs_);

    int alive_counting(int ypos, int xpos, Cell& rhs);

    /** This function will store the living and dead cells of the present generation 
        for future comparison with the cells of the future generation.*/
    void GenBackup (Cell& a);

    void future (Cell& a);

    /** This function will compare the past and future generations and say if the 
        board is stable or not.*/
    void GenCompare ( void );

    void print (std::ofstream& ofs_) const;
	
	bool st ( void );

	bool ex ( void );

    Cell & operator= (Cell & a); // Testindo new operator iqual

    /*Possible going to receive it's next form. Going to check if they are equal. 
      if yes, then it is stable.*/
//	void stable (Cell& next);
};

#endif
