#include <Bonus/SpeedGhostBonus.hpp>
#include <iostream>

using namespace std;

SpeedGhostBonus::SpeedGhostBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,(char*)"sprites/Bonus/bonusSpeedGhost.bmp"){	
}

SpeedGhostBonus::SpeedGhostBonus(const SpeedGhostBonus &bonus): Bonus(bonus){}


int SpeedGhostBonus::getPoint(){
	return 500;
}

char SpeedGhostBonus::getBonusType(){
	return '#';
}


shared_ptr<SpeedGhostBonus> SpeedGhostBonus::clone(){
	return make_shared<SpeedGhostBonus>(*this);
}