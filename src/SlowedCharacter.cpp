#include <SlowedCharacter.hpp>


SlowedCharacter::SlowedCharacter(shared_ptr<Character> c):CharacterDecorator(c){	
}

int SlowedCharacter::getSpeed(){	
	return 0.75*character_->getSpeed();
		
}

