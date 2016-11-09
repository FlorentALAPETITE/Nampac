#include <Bonus/SlowPacmanBonus.hpp>
#include <iostream>

using namespace std;

SlowPacmanBonus::SlowPacmanBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,"sprites/Bonus/bonusSlowPacman.bmp"){	
}


int SlowPacmanBonus::getPoint(){
	return 500;
}

char SlowPacmanBonus::getBonusType(){
	return '-';
}