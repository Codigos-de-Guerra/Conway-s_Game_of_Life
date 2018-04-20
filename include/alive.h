#ifndef ALIVE_H
#define ALIVE_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "cell.h"

/// Function to define the alive cells
void set_alive(std::string file, std::ifstream& ifs_);

/// Function to count the alive cells
int alive_counting(int ypos, int xpos, Cell& rhs);

#endif