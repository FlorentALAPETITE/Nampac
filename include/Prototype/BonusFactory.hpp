#ifndef DEF_BONUSFACTORY
#define DEF_BONUSFACTORY

#include <Bonus/Bonus.hpp>
#include <Bonus/Gum.hpp>
#include <Bonus/SlowGhostBonus.hpp>
#include <Bonus/SpeedGhostBonus.hpp>
#include <Bonus/SlowPacmanBonus.hpp>
#include <Bonus/SpeedPacmanBonus.hpp>
#include <Bonus/HunterBonus.hpp>
#include <Bonus/StupidGhostBonus.hpp>
#include <memory>
#include <SDL2/SDL.h>

using namespace std;


/**
	 * 
	 * \brief Bonus factory class implementation for the Nampac map creation (using a Prototype Pattern).
	 * \author Florent ALAPETITE / Dorian LATOUCHE
	 *
	 * Class that implements the dynamical creation method for the bonuses using the Prototype Pattern. Bonuses are contained in MapElement (see the class definition).
	 *
 	*/	
class BonusFactory {
	

	public:


		/**		
		 * BonusFactory(const int sizeSprite, SDL_Renderer* renderer);
		 * \brief Bonus factory constructor.
		 *
		 * \param sizeSprite : general sprite size (default : 25px).		
		 * \param renderer : unique SDL_Renderer used to render the game.
		
		*/
		BonusFactory(const int sizeSprite, SDL_Renderer* renderer);

		/**
		 * shared_ptr<Bonus> createBonus(const char type, const unsigned int c, const unsigned int  l, const int sizeSprite, SDL_Renderer* renderer);
		 * \brief Bonus creation method.
		 *
		 * \param type : bonus type of the required bonus.
		 * \param c : column position of the MapElement that require the bonus.
		 * \param l : line position of the MapElement that require the bonus.
		 * \param gumNumber: pointer to the number of gum bonuses.	
		 * 
		 * \return shared_ptr<Bonus> : pointer to the required bonus.
		 
		 */
		shared_ptr<Bonus> createBonus(const char type, const unsigned int c, const unsigned int  l,int &gumNumber);

	private:
		shared_ptr<Gum> gumBonusPrototype_;
		shared_ptr<SlowGhostBonus> slowGhostBonusPrototype_;
		shared_ptr<SpeedGhostBonus> speedGhostBonusPrototype_;
		shared_ptr<SpeedPacmanBonus> speedPacmanBonusPrototype_;
		shared_ptr<SlowPacmanBonus> slowPacmanBonusPrototype_;
		shared_ptr<HunterBonus> hunterBonusPrototype_;
		shared_ptr<StupidGhostBonus> stupidGhostBonusPrototype_;

		int sizeSprite_;

};


#endif