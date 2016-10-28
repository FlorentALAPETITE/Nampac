
#include <Lane.hpp>
#include <iostream>


bool Lane::canBeCrossed(){
	return true;
}

Lane::Lane(int posX, int posY,SDL_Renderer* renderer):MapElement((char*)"sprites/lane.bmp",posX,posY,renderer){
	Gomme bonus_(renderer);
	bonus_.setBonusTextureRect(posX, posY);
}

Bonus* Lane::getBonus(){ 
	std::cout << "lane";
	return bonus_; 
}
