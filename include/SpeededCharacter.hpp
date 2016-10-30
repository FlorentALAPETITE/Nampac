#ifndef DEF_SPEEDEDCHARACTER
#define DEF_SPEEDEDCHARACTER

#include <CharacterDecorator.hpp>
#include <Character.hpp>

class SpeededCharacter : public CharacterDecorator {

	public:
		SpeededCharacter(shared_ptr<Character>);
		int getSpeed() override;
	
};


#endif