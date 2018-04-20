#include "cell.h"

/*!
*
*\ Cell object contructors
*/

Cell::Cell(int height, int lenght); {
    ptr_M = new char*[height];
    for(int i=0; i < height; i++) {
    	*(ptr_M+i) = new char[lenght];
    }

    lin = height;
    col = lenght;

}

/*------------------------Respectively, it's destructor.------------------ */
// Freeing previous allocated space.
~Cell::Cell() {
    for(int i=0; i < lin; i++) {
    	delete [] ptr_M[i];
    }
    delete [] ptr_M;
}  

