#ifndef DEF_SLOWPACMANBONUS
#define DEF_SLOWPACMANBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete bonus SlowPacmanBonus implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete bonus implementation : SlowPacmanBonus. The SlowPacmanBonus ask the decoration of the Pacman with the SlowedCharacter class. Add +500 pts to the player score.
 *
 */	
class SlowPacmanBonus : public Bonus,  public Prototype<SlowPacmanBonus>{
	public:
		/**
		* SlowPacmanBonus(SDL_Renderer* renderer, int posX, int posY);
		* \brief SlowPacmanBonus constructor.
		*
		* \param renderer : unique SDL_Renderer used to render the game.
		* \param posX : X position in the 700x775 map. 
		* \param posY : Y position in the 700x775 map.
		*/
		SlowPacmanBonus(SDL_Renderer* renderer,int posX, int posY);	

		/**
		 * SlowPacmanBonus(const SlowPacmanBonus &bonus);
		 * \brief SlowPacmanBonus copy constructor.
		 * \param bonus : SlowPacmanBonus bonus to copy;
		*/
		SlowPacmanBonus(const SlowPacmanBonus &bonus);

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
		 * \return char : '-' : SlowPacmanBonus bonus type.
		 */
		char getBonusType() override;

		/**
		 *  shared_ptr<SlowPacmanBonus> clone(int posX,int posY) override;
		 * \brief Prototype method used to instantiate a new SlowPacmanBonus object. Change the created SlowPacmanBonus position to (posX,posY).
		 *
		 * \return shared_ptr<SlowPacmanBonus> the new object created with the prototype.
		 */
		shared_ptr<SlowPacmanBonus> clone(int posX,int posY) override;

};

#endif