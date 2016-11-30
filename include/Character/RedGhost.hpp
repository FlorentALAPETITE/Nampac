#ifndef DEF_REDGHOST
#define DEF_REDGHOST


#include <Character/Ghost.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;


/**
 * \brief Red ghost implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Red Ghost. By default, the red ghost is a CHASE ghost.
 *
 */

class RedGhost : public Ghost, public Prototype<RedGhost>{

	public:
		/**
		 * RedGhost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Red Ghost constructor. 
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 */
		RedGhost(int posX, int posY, SDL_Renderer* renderer);

		/**
		 * 	RedGhost(const RedGhost &rg);
		 * \brief RedGhost copy constructor.
		 * \param rg : red ghost to copy;
		*/
		RedGhost(const RedGhost &rg);

		/**
		 * 	void backToClassicState() override;
		 * \brief Change the current ghost state to his classic state : GhostMovementChase.		
		 */
		void backToClassicState() override;

		/**
		 *  shared_ptr<RedGhost> clone(int posX,int poxY) override;
		 * \brief Prototype method used to instantiate a new Red Ghost object. Change the created Ghost position to (posX,posY).
		 *
		 * \return shared_ptr<RedGhost> the new object created with the prototype.
		 */
		shared_ptr<RedGhost> clone(int posX,int poxY) override;
		
	private:
};


#endif

