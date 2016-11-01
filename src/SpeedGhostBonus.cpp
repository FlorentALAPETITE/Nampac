#include <SpeedGhostBonus.hpp>
#include <iostream>

using namespace std;

SpeedGhostBonus::SpeedGhostBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,"sprites/bonusSpeedGhost.bmp"){	
}


int SpeedGhostBonus::getPoint(){
	return 500;
}

char SpeedGhostBonus::getBonusType(){
	return '#';
}