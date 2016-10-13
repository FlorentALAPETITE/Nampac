
#include <Lane.hpp>


bool Lane::canBeCrossed(){
	return true;
}

Lane::Lane(int posX, int posY,SDL_Renderer* renderer):MapElement("sprites/lane.bmp",posX,posY,renderer){}