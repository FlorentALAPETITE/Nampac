
#include <Lane.hpp>
#include <Gum.hpp>
#include <iostream>


bool Lane::canBeCrossed(){
	return true;
}

Lane::Lane(int posX, int posY,SDL_Renderer* renderer):MapElement((char*)"sprites/lane.bmp",posX,posY,renderer){
	bonus_ = new Gum(renderer, posX+9, posY+9);	
}

Bonus* Lane::getBonus(){ 	
	return bonus_; 
}
