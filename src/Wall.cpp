#include <MapElement/Wall.hpp>
#include <iostream>


bool Wall::canBeCrossed(){
	return false;
}

Wall::Wall(int posX, int posY,SDL_Renderer* renderer):MapElement((char*)"sprites/MapElement/wall.bmp",posX,posY,renderer){}


Wall::Wall(const Wall &wall):MapElement(wall){}

shared_ptr<Wall> Wall::clone(int c, int l){
	shared_ptr<Wall> wall = make_shared<Wall>(*this);
	wall->setPosition(c,l);
	return wall;
}

void Wall::setBonus(shared_ptr<Bonus> b){}