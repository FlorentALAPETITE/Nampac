#include <Bonus/SlowGhostBonus.hpp>
#include <iostream>

using namespace std;

SlowGhostBonus::SlowGhostBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,(char*)"sprites/Bonus/bonusSlowGhost.bmp"){	
}

SlowGhostBonus::SlowGhostBonus(const SlowGhostBonus &bonus): Bonus(bonus){}



int SlowGhostBonus::getPoint(){
	return 100;
}

char SlowGhostBonus::getBonusType(){
	return '~';
}


shared_ptr<SlowGhostBonus> SlowGhostBonus::clone(int c, int l){
	shared_ptr<SlowGhostBonus> bonus = make_shared<SlowGhostBonus>(*this);
	bonus->setPosition(c,l);
	return bonus;
}