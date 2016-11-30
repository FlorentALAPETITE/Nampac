#ifndef DEF_ORANGEGHOST
#define DEF_ORANGEGHOST


#include <Character/Ghost.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;


/**
 * \brief Orange ghost implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Orange Ghost. By default, the orange ghost is a STUPID ghost.
 *
 */

class OrangeGhost : public Ghost, public Prototype<OrangeGhost>{

	public:
		/**
		 * OrangeGhost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Orange Ghost constructor. 
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 */
		OrangeGhost(int posX, int posY, SDL_Renderer* renderer);

		/**
		 * 	OrangeGhost(const OrangeGhost &og);
		 * \brief OrangeGhost copy constructor.
		 * \param og : orange ghost to copy;
		*/
		OrangeGhost(const OrangeGhost &og);

		/**
		 * 	void backToClassicState() override;
		 * \brief Change the current ghost state to his classic state : GhostMovementStupid.		
		 */
		void backToClassicState() override;

		/**
		 *  shared_ptr<OrangeGhost> clone(int posX,int poxY) override;
		 * \brief Prototype method used to instantiate a new Orange Ghost object. Change the created Ghost position to (posX,posY).
		 *
		 * \return shared_ptr<OrangeGhost> the new object created with the prototype.
		 */
		shared_ptr<OrangeGhost> clone(int posX,int poxY) override;

	private:
};


#endif

