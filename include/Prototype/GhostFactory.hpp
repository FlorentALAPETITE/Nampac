#ifndef DEF_GHOSTFACTORY
#define DEF_GHOSTFACTORY

#include <Character/RedGhost.hpp>
#include <Character/BlueGhost.hpp>
#include <Character/OrangeGhost.hpp>
#include <Character/PinkGhost.hpp>
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

/**
	 * 
	 * \brief Ghost factory class implementation for the Nampac map creation (using a Prototype Pattern).
	 * \author Florent ALAPETITE / Dorian LATOUCHE
	 *
	 * Class that implements the dynamical creation method for the ghosts using the Prototype Pattern.
	 *
 	*/	

class GhostFactory {

	public:

		/**		
		 * GhostFactory(const int sizeSprite, SDL_Renderer* renderer);
		 * \brief GhostFactory constructor.
		 *
		 * \param sizeSprite : general sprite size (default : 25px).		
		 * \param renderer : unique SDL_Renderer used to render the game.
		
		*/
		GhostFactory(const int sizeSprite, SDL_Renderer* renderer);

		/**
		 * shared_ptr<Ghost> createGhost(const char type, const unsigned int c, const unsigned int  l);
		 * \brief Ghost creation method using the Prototype pattern. The required Ghost is created using the clone method of the corresponding prototype attribute.
		 *
		 * \param type : type of the required Ghost.
		 * \param c : column position of the Ghost on the map.
		 * \param l : line position of the Ghost on the map.

		 * 
		 * \return shared_ptr<Ghost> : pointer to the required Ghost.
		 
		 */
		shared_ptr<Ghost> createGhost(const char type, const unsigned int c, const unsigned int  l);

	private:
		shared_ptr<BlueGhost> blueGhostPrototype_;
		shared_ptr<OrangeGhost> orangeGhostPrototype_;
		shared_ptr<RedGhost> redGhostPrototype_;
		shared_ptr<PinkGhost> pinkGhostPrototype_;

		int sizeSprite_;

};


#endif