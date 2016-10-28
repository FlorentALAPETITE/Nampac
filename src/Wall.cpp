
#include <Wall.hpp>
#include <iostream>


bool Wall::canBeCrossed(){
	return false;
}

Wall::Wall(int posX, int posY,SDL_Renderer* renderer):MapElement((char*)"sprites/wall.bmp",posX,posY,renderer){}

Bonus* Wall::getBonus(){
	std::cout << "wall";
	return NULL;
}