#include <CharacterDecorator/SlowedCharacter.hpp>
#include <math.h>  

SlowedCharacter::SlowedCharacter(shared_ptr<Character> c):CharacterDecorator(c){	
}

int SlowedCharacter::getSpeed(){	
	int speed = character_->getSpeed();
	return round(0.75*speed);
		
}

