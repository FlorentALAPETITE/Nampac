#include <Bonus/StupidGhostBonus.hpp>
#include <iostream>

using namespace std;

StupidGhostBonus::StupidGhostBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,"sprites/Bonus/bonusStupidGhost.bmp"){	
}


int StupidGhostBonus::getPoint(){
	return 100;
}

char StupidGhostBonus::getBonusType(){
	return '!';
}