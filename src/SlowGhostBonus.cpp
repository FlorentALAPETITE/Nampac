#include <SlowGhostBonus.hpp>
#include <iostream>

using namespace std;

SlowGhostBonus::SlowGhostBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY,"sprites/bonusSlowGhost.bmp"){	
}


int SlowGhostBonus::getPoint(){
	return 100;
}

int SlowGhostBonus::getBonusType(){
	return 1;
}