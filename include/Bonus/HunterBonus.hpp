#ifndef DEF_HUNTERBONUS
#define DEF_HUNTERBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete bonus HunterBonus implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete bonus implementation : HunterBonus. The HunterBonus asks the PacmanState modification to HunterState (can eat ghosts). Add +100 pts to the player score.
 *
 */	
class HunterBonus : public Bonus, public Prototype<HunterBonus>{
	public:
		/**
		* HunterBonus(SDL_Renderer* renderer, int posX, int posY);
		* \brief HunterBonus constructor.
		*
		* \param renderer : unique SDL_Renderer used to render the game.
		* \param posX : X position in the 700x775 map. 
		* \param posY : Y position in the 700x775 map.
		*/
		HunterBonus(SDL_Renderer* renderer,int posX, int posY);	

		/**
		 * HunterBonus(const HunterBonus &bonus);
		 * \brief HunterBonus copy constructor.
		 * \param bonus : HunterBonus bonus to copy;
		*/
		HunterBonus(const HunterBonus &bonus);

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
		 * \return char : '$' : HunterBonus bonus type.
		 */
		char getBonusType() override;

		/**
		 *  shared_ptr<HunterBonus> clone(int posX,int posY) override;
		 * \brief Prototype method used to instantiate a new HunterBonus object. Change the created HunterBonus position to (posX,posY).
		 *
		 * \return shared_ptr<HunterBonus> the new object created with the prototype.
		 */
		shared_ptr<HunterBonus> clone(int posX,int posY) override;

};

#endif