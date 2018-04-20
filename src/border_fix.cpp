#include <iostream>

 *border_fix(){
		
	if( height == 0  )
		fix_border->ymin = 0;
	if( width == 0  )
		fix_border->xmin = 0;
	if( height == screen->height-1  )
		fix_border->ymax = 0;
	if( width == screen->width-1  )
		fix_border->xmax = 0;

return border_fix;
}
