#ifndef DEF_REDGHOST
#define DEF_REDGHOST


#include <Ghost.hpp>

using namespace std;


/**
 * \file RedGhost.cpp
 * \brief Red ghost implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Red Ghost;
 *
 */

class RedGhost : public Ghost{

	public:
		/**
		 * RedGhost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Red Ghost constructor. By default, the red ghost is a CHASE ghost.
		 *
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 */
		RedGhost(int posX, int posY, SDL_Renderer* renderer);
		void backToClassicState() override;

	private:
};


#endif

