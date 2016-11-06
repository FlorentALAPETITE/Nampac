#include <Gum.hpp>
#include <iostream>

using namespace std;

Gum::Gum(SDL_Renderer* renderer, int posX, int posY):Bonus(renderer,posX,posY,8,"sprites/gum.bmp"){	
}



int Gum::getPoint(){
	return 50;
}

char Gum::getBonusType(){
	return '0';
}