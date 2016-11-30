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

		/**
		 * 	PinkGhost(const PinkGhost &pg);
		 * \brief PinkGhost copy constructor.
		 * \param pg : pink ghost to copy;
		*/
		PinkGhost(const PinkGhost &pg);

		/**
		 * 	void backToClassicState() override;
		 * \brief Change the current ghost state to his classic state : GhostMovementAmbush.		
		 */
		void backToClassicState() override;

		/**
		 *  shared_ptr<PinkGhost> clone(int posX,int poxY) override;
		 * \brief Prototype method used to instantiate a new Pink Ghost object. Change the created Ghost position to (posX,posY).
		 *
		 * \return shared_ptr<PinkGhost> the new object created with the prototype.
		 */
		shared_ptr<PinkGhost> clone(int posX,int poxY) override;

	private:
};


#endif

