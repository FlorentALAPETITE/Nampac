
#include <Wall.hpp>


bool Wall::canBeCrossed(){
	return false;
}

Wall::Wall(char* sl, int posX, int posY,SDL_Renderer* renderer):MapElement(sl,posX,posY,renderer){}