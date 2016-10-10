
#include <Lane.hpp>


bool Lane::canBeCrossed(){
	return true;
}

Lane::Lane(char* sl, int posX, int posY,SDL_Renderer* renderer):MapElement(sl,posX,posY,renderer){}