#include <SpeededCharacter.hpp>


SpeededCharacter::SpeededCharacter(shared_ptr<Character> c):CharacterDecorator(c){	
}

int SpeededCharacter::getSpeed(){	
	return character_->getSpeed()+2;
}

