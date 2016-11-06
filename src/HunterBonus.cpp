#include <HunterBonus.hpp>
#include <iostream>

using namespace std;

HunterBonus::HunterBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,"sprites/bonusSlowPacman.bmp"){	
}


int HunterBonus::getPoint(){
	return 500;
}

char HunterBonus::getBonusType(){
	return '$';
}