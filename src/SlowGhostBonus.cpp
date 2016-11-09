#include <Bonus/SlowGhostBonus.hpp>
#include <iostream>

using namespace std;

SlowGhostBonus::SlowGhostBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,"sprites/Bonus/bonusSlowGhost.bmp"){	
}


int SlowGhostBonus::getPoint(){
	return 100;
}

char SlowGhostBonus::getBonusType(){
	return '~';
}