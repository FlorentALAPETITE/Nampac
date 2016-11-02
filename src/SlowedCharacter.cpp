#include <SlowedCharacter.hpp>
#include <math.h>  

SlowedCharacter::SlowedCharacter(shared_ptr<Character> c):CharacterDecorator(c){	
}

int SlowedCharacter::getSpeed(){	
	return round(0.75*character_->getSpeed());
		
}

