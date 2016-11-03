#include <SpeededCharacter.hpp>
#include <math.h>  

SpeededCharacter::SpeededCharacter(shared_ptr<Character> c):CharacterDecorator(c){	
}

int SpeededCharacter::getSpeed(){	
	int speed = character_->getSpeed();
	return round(1.25*speed);
}

