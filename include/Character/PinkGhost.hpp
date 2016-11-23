#ifndef DEF_PINKGHOST
#define DEF_PINKGHOST


#include <Character/Ghost.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;


/**
 * \brief Pink ghost implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Pink Ghost. By default, the pink ghost is an AMBUSH ghost.
 *
 */


class PinkGhost : public Ghost, public Prototype<PinkGhost>{

	public:
		/**
		 * PinkGhost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Pink Ghost constructor.		 *
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 */
		PinkGhost(int posX, int posY, SDL_Renderer* renderer);
		PinkGhost(const PinkGhost &pg);
		void backToClassicState() override;
		shared_ptr<PinkGhost> clone(int,int) override;

	private:
};


#endif

