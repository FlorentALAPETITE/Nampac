#include <Bonus/HunterBonus.hpp>
#include <iostream>

using namespace std;

HunterBonus::HunterBonus(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY, 20,(char*)"sprites/Bonus/bonusHunter.bmp"){	
}

HunterBonus::HunterBonus(const HunterBonus &bonus): Bonus(bonus){}

int HunterBonus::getPoint(){
	return 100;
}

char HunterBonus::getBonusType(){
	return '$';
}

shared_ptr<HunterBonus> HunterBonus::clone(int c, int l){
	shared_ptr<HunterBonus> bonus = make_shared<HunterBonus>(*this);
	bonus->setPosition(c,l);
	return bonus;
}