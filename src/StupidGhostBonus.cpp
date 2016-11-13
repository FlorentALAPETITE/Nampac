#include <Bonus/StupidGhostBonus.hpp>
#include <iostream>

using namespace std;

StupidGhostBonus::StupidGhostBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,(char*)"sprites/Bonus/bonusStupidGhost.bmp"){	
}

StupidGhostBonus::StupidGhostBonus(const StupidGhostBonus &bonus): Bonus(bonus){}



int StupidGhostBonus::getPoint(){
	return 100;
}

char StupidGhostBonus::getBonusType(){
	return '!';
}


shared_ptr<StupidGhostBonus> StupidGhostBonus::clone(int c, int l){
	shared_ptr<StupidGhostBonus> bonus = make_shared<StupidGhostBonus>(*this);
	bonus->setPosition(c,l);
	return bonus;
}