#ifndef ALIVE_H
#define ALIVE_H

#include "cell.hpp"
#include <cstring>
#include <fstream>
#include <algorithm>

/// Function to define the alive cells
void Cell::set_alive(std::string file, std::ifstream& ifs_);

/// Function to count the alive cells
int Cell::alive_counting(int ypos, int xpos, Cell& rhs);

#endif
