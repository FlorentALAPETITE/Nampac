#include <MapElement/Wall.hpp>
#include <iostream>


bool Wall::canBeCrossed(){
	return false;
}

Wall::Wall(int posX, int posY,SDL_Renderer* renderer):MapElement((char*)"sprites/MapElement/wall.bmp",posX,posY,renderer, nullptr){}

