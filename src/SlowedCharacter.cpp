#include <SlowedCharacter.hpp>


SlowedCharacter::SlowedCharacter(shared_ptr<Character> c):CharacterDecorator(c){	
}

int SlowedCharacter::getSpeed(){	
	return 0.6*character_->getSpeed();
}

