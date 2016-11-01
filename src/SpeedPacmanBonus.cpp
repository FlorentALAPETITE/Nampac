#include <SpeedPacmanBonus.hpp>
#include <iostream>

using namespace std;

SpeedPacmanBonus::SpeedPacmanBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,"sprites/bonusSpeedPacman.bmp"){	
}


int SpeedPacmanBonus::getPoint(){
	return 100;
}

char SpeedPacmanBonus::getBonusType(){
	return '+';
}