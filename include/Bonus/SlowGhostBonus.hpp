#ifndef DEF_SLOWGHOSTBONUS
#define DEF_SLOWGHOSTBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;


/**
 * \brief Concrete bonus SlowGhostBonus implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete bonus implementation : SlowGhostBonus. The SlowGhostBonus ask the decoration of all ghosts with the SlowedCharacter class. Add +100 pts to the player score.
 *
 */	
class SlowGhostBonus : public Bonus, public Prototype<SlowGhostBonus>{
	public:
		/**
		* SlowGhostBonus(SDL_Renderer* renderer, int posX, int posY);
		* \brief SlowGhostBonus constructor.
		*
		* \param renderer : unique SDL_Renderer used to render the game.
		* \param posX : X position in the 700x775 map. 
		* \param posY : Y position in the 700x775 map.
		*/
		SlowGhostBonus(SDL_Renderer* renderer,int posX, int posY);	

		/**
		 * SlowGhostBonus(const SlowGhostBonus &bonus);
		 * \brief SlowGhostBonus copy constructor.
		 * \param bonus : SlowGhostBonus bonus to copy;
		*/
		SlowGhostBonus(const SlowGhostBonus &bonus);

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
		 * \return char : '~' : SlowGhostBonus bonus type.
		 */
		char getBonusType() override;

		/**
		 *  shared_ptr<SlowGhostBonus> clone(int posX,int posY) override;
		 * \brief Prototype method used to instantiate a new SlowGhostBonus object. Change the created SlowGhostBonus position to (posX,posY).
		 *
		 * \return shared_ptr<SlowGhostBonus> the new object created with the prototype.
		 */
		shared_ptr<SlowGhostBonus> clone(int posX,int posY) override;

};

#endif