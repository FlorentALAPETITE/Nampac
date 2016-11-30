#ifndef DEF_BLUEGHOST
#define DEF_BLUEGHOST

#include <Character/Ghost.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;


/**
 * \brief Blue ghost implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Blue Ghost. By default, the blue ghost is an UNPREDICTABLE ghost.
 *
 */

class BlueGhost : public Ghost, public Prototype<BlueGhost>{

	public:
		/**
		 * BlueGhost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Blue Ghost constructor.
		 *
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 */
		BlueGhost(int posX, int posY, SDL_Renderer* renderer);

		/**
		 * 	BlueGhost(const BlueGhost &bg);
		 * \brief BlueGhost copy constructor.
		 * \param bg : blue ghost to copy;
		*/
		BlueGhost(const BlueGhost &bg);

		/**
		 * 	void backToClassicState() override;
		 * \brief Change the current ghost state to his classic state : GhostMovementUnpredictable.		
		 */
		void backToClassicState() override;

		/**
		 *  shared_ptr<BlueGhost> clone(int posX,int poxY) override;
		 * \brief Prototype method used to instantiate a new Blue Ghost object. Change the created Ghost position to (posX,posY).
		 *
		 * \return shared_ptr<BlueGhost> the new object created with the prototype.
		 */
		shared_ptr<BlueGhost> clone(int posX,int poxY) override;

	private:
};


#endif

