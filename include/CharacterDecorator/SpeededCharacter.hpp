#ifndef DEF_SPEEDEDCHARACTER
#define DEF_SPEEDEDCHARACTER

#include <CharacterDecorator/CharacterDecorator.hpp>

/**
 * \brief Decorator concrete implementation for the Nampac : SpeededCharacter.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Decorator concrete class implementation for the Nampac game. The SpeededCharacter decorate a character and increase its speed. Non-modified methods are calling the decorated object's method.
 *
 */

class SpeededCharacter : public CharacterDecorator {

	public:
		/**
		 * SpeededCharacter(shared_ptr<Character> c);
		 * \brief SpeededCharacter constructor.
		 *		
		 * \param c : the decorated character.
		 */
		SpeededCharacter(shared_ptr<Character> c);

		/**
		 * int getSpeed() override;	
		 * \brief Decorated getter for the character speed.
		 *		
		 * \return int : 125% of the decorated character speed.
		 */
		int getSpeed() override;
	
};


#endif