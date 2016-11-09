#include <MapElement/Lane.hpp>
#include <iostream>


bool Lane::canBeCrossed(){
	return true;
}

Lane::Lane(int posX, int posY,SDL_Renderer* renderer, shared_ptr<Bonus> b):MapElement((char*)"sprites/MapElement/lane.bmp",posX,posY,renderer,b){		
}

