#ifndef DEF_SLOWEDCHARACTER
#define DEF_SLOWEDCHARACTER

#include <CharacterDecorator.hpp>
#include <Character.hpp>

class SlowedCharacter : public CharacterDecorator {

	public:
		SlowedCharacter(shared_ptr<Character>);
		int getSpeed() override;		
	
};


#endif