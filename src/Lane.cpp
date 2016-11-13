#include <MapElement/Lane.hpp>
#include <iostream>


bool Lane::canBeCrossed(){
	return true;
}

Lane::Lane(int posX, int posY,SDL_Renderer* renderer):MapElement((char*)"sprites/MapElement/lane.bmp",posX,posY,renderer){		
}

Lane::Lane(const Lane &lane):MapElement(lane){}

shared_ptr<Lane> Lane::clone(int c, int l){
	shared_ptr<Lane> bonus = make_shared<Lane>(*this);
	bonus->setPosition(c,l);
	return bonus;
}