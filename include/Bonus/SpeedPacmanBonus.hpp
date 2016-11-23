#ifndef DEF_SPEEDPACMANBONUS
#define DEF_SPEEDPACMANBONUS

#include <Bonus/Bonus.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete bonus SpeedPacmanBonus implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete bonus implementation : SpeedPacmanBonus. The SpeedPacmanBonus ask the decoration of the Pacman with the SpeededCharacter class. Add +100 pts to the player score.
 *
 */	
class SpeedPacmanBonus : public Bonus, public Prototype<SpeedPacmanBonus>{
	public:
		/**
		* SpeedPacmanBonus(SDL_Renderer* renderer, int posX, int posY);
		* \brief SpeedPacmanBonus constructor.
		*
		* \param renderer : unique SDL_Renderer used to render the game.
		* \param posX : X position in the 700x775 map. 
		* \param posY : Y position in the 700x775 map.
		*/
		SpeedPacmanBonus(SDL_Renderer* renderer,int posX, int posY);	

		/**
		 * SpeedPacmanBonus(const SpeedPacmanBonus &bonus);
		 * \brief SpeedPacmanBonus copy constructor.
		 * \param bonus : SpeedPacmanBonus bonus to copy;
		*/
		SpeedPacmanBonus(const SpeedPacmanBonus &bonus);

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
		 * \return char : '+' : SpeedPacmanBonus bonus type.
		 */
		char getBonusType() override;

		/**
		 *  shared_ptr<SpeedPacmanBonus> clone(int posX,int posY) override;
		 * \brief Prototype method used to instantiate a new SpeedPacmanBonus object. Change the created SpeedPacmanBonus position to (posX,posY).
		 *
		 * \return shared_ptr<SpeedPacmanBonus> the new object created with the prototype.
		 */
		shared_ptr<SpeedPacmanBonus> clone(int posX,int posY) override;

};

#endif