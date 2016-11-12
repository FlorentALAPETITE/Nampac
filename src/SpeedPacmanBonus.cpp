#include <Bonus/SpeedPacmanBonus.hpp>
#include <iostream>

using namespace std;

SpeedPacmanBonus::SpeedPacmanBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,(char*)"sprites/Bonus/bonusSpeedPacman.bmp"){	
}

SpeedPacmanBonus::SpeedPacmanBonus(const SpeedPacmanBonus &bonus): Bonus(bonus){}


int SpeedPacmanBonus::getPoint(){
	return 100;
}

char SpeedPacmanBonus::getBonusType(){
	return '+';
}


shared_ptr<SpeedPacmanBonus> SpeedPacmanBonus::clone(){
	return make_shared<SpeedPacmanBonus>(*this);
}