#ifndef DEF_SLOWEDCHARACTER
#define DEF_SLOWEDCHARACTER

#include <CharacterDecorator/CharacterDecorator.hpp>

/**
 * \brief Decorator concrete implementation for the Nampac : SlowedCharacter.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Decorator concrete class implementation for the Nampac game. The SlowedCharacter decorate a character and decrease its speed. Non-modified methods are calling the decorated object's method.
 *
 */

class SlowedCharacter : public CharacterDecorator {

	public:
		/**
		 * SlowedCharacter(shared_ptr<Character> c);
		 * \brief SlowedCharacter constructor.
		 *		
		 * \param c : the decorated character.
		 */
		SlowedCharacter(shared_ptr<Character> c);

		/**
		 * int getSpeed() override;	
		 * \brief Decorated getter for the character speed.
		 *		
		 * \return int : 75% of the decorated character speed.
		 */
		int getSpeed() override;		
	
};


#endif