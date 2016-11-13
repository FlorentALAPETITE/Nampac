#ifndef DEF_ORANGEGHOST
#define DEF_ORANGEGHOST


#include <Character/Ghost.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;


/**
 * \file OrangeGhost.cpp
 * \brief Orange ghost implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Orange Ghost;
 *
 */

class OrangeGhost : public Ghost, public Prototype<OrangeGhost>{

	public:
		/**
		 * OrangeGhost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Orange Ghost constructor. By default, the orange ghost is a STUPID ghost.
		 *
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 */
		OrangeGhost(int posX, int posY, SDL_Renderer* renderer);
		OrangeGhost(const OrangeGhost &og);
		void backToClassicState() override;
		shared_ptr<OrangeGhost> clone(int,int) override;

	private:
};


#endif

