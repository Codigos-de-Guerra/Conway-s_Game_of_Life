/*!
 * C++ implementation of Conway's game of life
 * @date April, 19th.
 */

#include <iostream>
#include <vector>
#include <algorithm>


/// Define X and Y as the width and the hight
static void nextGeneration(){

/// Finding neighbours alive
	count = 0;
	for(int i=xpos-1; i < xpos+2; i++) {
		if(rhs->ptr_M[ypos-1][i] == rhs.live_cell) {
			count++;
		}
					
	}
	for(int i=xpos-1; i < xpos+2; i++) {
		if(rhs->ptr_M[ypos][i] == rhs.live_cell) {
			if( i == xpos ) continue;
				count++;
																	
		}
					
	}
	for(int i=xpos-1; i < xpos+2; i++) {
		if(rhs->ptr_M[ypos+1][i] == rhs.live_cell) {
			count++;
			}

	}
}

Borders correct_borders(  int m_y, int m_x, Borders *fix_border  ){
		
		if( height == 0  )
					fix_border->ymin = 0;
			if( width == 0  )
						fix_border->xmin = 0;
				if( height == screen->height-1  )
							fix_border->ymax = 0;
					if( width == screen->width-1  )
								fix_border->xmax = 0;

						return fix_border;

}
