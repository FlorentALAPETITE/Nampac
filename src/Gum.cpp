#include <Bonus/Gum.hpp>
#include <iostream>

using namespace std;

Gum::Gum(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY,8,(char*)"sprites/Bonus/gum.bmp"){	
}

Gum::Gum(const Gum &bonus): Bonus(bonus){}



int Gum::getPoint(){
	return 50;
}

char Gum::getBonusType(){
	return '0';
}

shared_ptr<Gum> Gum::clone(int c, int l){
	shared_ptr<Gum> bonus = make_shared<Gum>(*this);
	bonus->setPosition(c,l);
	return bonus;
}