#include <Bonus/SlowPacmanBonus.hpp>
#include <iostream>

using namespace std;

SlowPacmanBonus::SlowPacmanBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,(char*)"sprites/Bonus/bonusSlowPacman.bmp"){	
}

SlowPacmanBonus::SlowPacmanBonus(const SlowPacmanBonus &bonus): Bonus(bonus){}


int SlowPacmanBonus::getPoint(){
	return 500;
}

char SlowPacmanBonus::getBonusType(){
	return '-';
}


shared_ptr<SlowPacmanBonus> SlowPacmanBonus::clone(int c, int l){
	shared_ptr<SlowPacmanBonus> bonus = make_shared<SlowPacmanBonus>(*this);
	bonus->setPosition(c,l);
	return bonus;
}