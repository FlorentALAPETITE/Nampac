#include <HunterBonus.hpp>
#include <iostream>

using namespace std;

HunterBonus::HunterBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,"sprites/bonusHunter.bmp"){	
}


int HunterBonus::getPoint(){
	return 100;
}

char HunterBonus::getBonusType(){
	return '$';
}