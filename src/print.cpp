#include "print.h"

void print (void) const {
			std::cout << "Colunas = " << col << "Linhas = " << lin << "\n";
			for(auto i=0; i < lin; i++) {
				for(auto j=0; j < col; j++) {
					std::cout << ptr_M[i][j];
				}
				std::cout << "\n";
			}
		}