#ifndef DEF_STUPIDGHOSTBONUS
#define DEF_STUPIDGHOSTBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete bonus StupidGhostBonus implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete bonus implementation : StupidGhostBonus. The StupidGhostBonus asks all ghosts to change their state to the GhostMovementStupid. Add +100 pts to the player score.
 *
 */	
class StupidGhostBonus : public Bonus, public Prototype<StupidGhostBonus>{
	public:
		/**
		* StupidGhostBonus(SDL_Renderer* renderer, int posX, int posY);
		* \brief StupidGhostBonus constructor.
		*
		* \param renderer : unique SDL_Renderer used to render the game.
		* \param posX : X position in the 700x775 map. 
		* \param posY : Y position in the 700x775 map.
		*/
		StupidGhostBonus(SDL_Renderer* renderer,int posX, int posY);	

		/**
		 * StupidGhostBonus(const StupidGhostBonus &bonus);
		 * \brief StupidGhostBonus copy constructor.
		 * \param bonus : StupidGhostBonus bonus to copy;
		*/
		StupidGhostBonus(const StupidGhostBonus &bonus);

		/**
		 * int getPoint() override;
		 * \brief Point getter.
		 *
		 * \return int : 100 pts
		  */
		int getPoint() override;

		/**
		 * char getBonusType() override;
		 * \brief Bonus type getter.
		 * \return char : '!' : StupidGhostBonus bonus type.
		 */
		char getBonusType() override;

		/**
		 *  shared_ptr<StupidGhostBonus> clone(int posX,int posY) override;
		 * \brief Prototype method used to instantiate a new StupidGhostBonus object. Change the created StupidGhostBonus position to (posX,posY).
		 *
		 * \return shared_ptr<StupidGhostBonus> the new object created with the prototype.
		 */
		shared_ptr<StupidGhostBonus> clone(int posX,int posY) override;

};

#endif