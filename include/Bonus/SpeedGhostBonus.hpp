#ifndef DEF_SPEEDGHOSTBONUS
#define DEF_SPEEDGHOSTBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete bonus SpeedGhostBonus implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete bonus implementation : SpeedGhostBonus. The SpeedGhostBonus ask the decoration of all ghosts with the SpeededCharacter class. Add +500 pts to the player score.
 *
 */	
class SpeedGhostBonus : public Bonus, public Prototype<SpeedGhostBonus>{
public:
		/**
		* SpeedGhostBonus(SDL_Renderer* renderer, int posX, int posY);
		* \brief SpeedGhostBonus constructor.
		*
		* \param renderer : unique SDL_Renderer used to render the game.
		* \param posX : X position in the 700x775 map. 
		* \param posY : Y position in the 700x775 map.
		*/
		SpeedGhostBonus(SDL_Renderer* renderer,int posX, int posY);	

		/**
		 * SpeedGhostBonus(const SpeedGhostBonus &bonus);
		 * \brief SpeedGhostBonus copy constructor.
		 * \param bonus : SpeedGhostBonus bonus to copy;
		*/
		SpeedGhostBonus(const SpeedGhostBonus &bonus);

		/**
		 * int getPoint() override;
		 * \brief Point getter.
		 *
		 * \return int : 500 pts
		  */
		int getPoint() override;

		/**
		 * char getBonusType() override;
		 * \brief Bonus type getter.
		 * \return char : '#' : SpeedGhostBonus bonus type.
		 */
		char getBonusType() override;

		/**
		 *  shared_ptr<SpeedGhostBonus> clone(int posX,int posY) override;
		 * \brief Prototype method used to instantiate a new SpeedGhostBonus object. Change the created SpeedGhostBonus position to (posX,posY).
		 *
		 * \return shared_ptr<SpeedGhostBonus> the new object created with the prototype.
		 */
		shared_ptr<SpeedGhostBonus> clone(int posX,int posY) override;

};

#endif