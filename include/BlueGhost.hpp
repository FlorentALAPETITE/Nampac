#ifndef DEF_BLUEGHOST
#define DEF_BLUEGHOST

#include <Ghost.hpp>

using namespace std;


/**
 * \file BlueGhost.cpp
 * \brief Blue ghost implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Blue Ghost;
 *
 */


class BlueGhost : public Ghost{

	public:
		/**
		 * BlueGhost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Blue Ghost constructor. By default, the blue ghost is an UNPREDICTABLE ghost.
		 *
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 */
		BlueGhost(int posX, int posY, SDL_Renderer* renderer);

	private:
};


#endif

