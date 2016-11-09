#ifndef DEF_SLOWEDCHARACTER
#define DEF_SLOWEDCHARACTER

#include <CharacterDecorator/CharacterDecorator.hpp>

class SlowedCharacter : public CharacterDecorator {

	public:
		SlowedCharacter(shared_ptr<Character>);
		int getSpeed() override;		
	
};


#endif