
#include <Wall.hpp>


bool Wall::canBeCrossed(){
	return false;
}

Wall::Wall(int posX, int posY,SDL_Renderer* renderer):MapElement("sprites/wall.bmp",posX,posY,renderer){}