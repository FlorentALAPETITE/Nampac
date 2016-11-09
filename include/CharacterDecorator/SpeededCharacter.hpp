#ifndef DEF_SPEEDEDCHARACTER
#define DEF_SPEEDEDCHARACTER

#include <CharacterDecorator/CharacterDecorator.hpp>

class SpeededCharacter : public CharacterDecorator {

	public:
		SpeededCharacter(shared_ptr<Character>);
		int getSpeed() override;
	
};


#endif