#ifndef DEF_BONUSFACTORY
#define DEF_BONUSFACTORY

#include <Bonus/Bonus.hpp>
#include <memory>
#include <SDL2/SDL.h>

using namespace std;


/**
	 * 
	 * \brief Abstract bonus factory class implementation for the Nampac map creation (Factory Pattern).
	 * \author Florent ALAPETITE / Dorian LATOUCHE
	 *
	 * Abstract class that implements the dynamical creation method for the bonuses. Bonuses are contained in MapElements (see the class definition).
	 *
 	*/	
class BonusFactory {
	

	public:
		/**
		 * virtual shared_ptr<Bonus> createBonus(const char type, const unsigned int c, const unsigned int  l, const int sizeSprite, SDL_Renderer* renderer) = 0;
		 * \brief Abstract bonus creation method.
		 *
		 * \param type : bonus type of the required bonus.
		 * \param c : column position of the MapElement that require the bonus.
		 * \param l : line position of the MapElement that require the bonus.
		 * \param sizeSprite : general sprite size (default : 25px).
		 * \param shared_ptr<Bonus> : pointer to the required bonus.
		 * \param gumNumber: pointer to the number of gum bonuses.
		 */
		virtual shared_ptr<Bonus> createBonus(const char type, const unsigned int c, const unsigned int  l, const int sizeSprite, SDL_Renderer* renderer,int &gumNumber) = 0;


};


#endif