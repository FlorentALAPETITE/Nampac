#ifndef DEF_LANE
#define DEF_LANE

#include <MapElement/MapElement.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete Lane implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete class that implements Lane behaviour. A Lane can contain a bonus and can be crossed by a Character.
 *
 */	

class Lane : public MapElement, public Prototype<Lane>{	

	public:	

		/**
		 * Lane(int posX, int posY,SDL_Renderer* renderer);
		 *
		 * \brief Lane constructor.
		 *		
		 * \param posX : X position of the Lane on the map.
		 * \param posY : Y position of the Lane on the map.
		 * \param renderer :  unique SDL_Renderer used to render the game.
		 */
		Lane(int posX, int posY,SDL_Renderer* renderer);

		/**
		 * Lane(const Lane &lane);
		 * \brief Lane copy contructor.
		 *		
		 * \param lane : existing Lane object pointer.
		 */
		Lane(const Lane &lane);

		/**
		 * bool canBeCrossed() override;
		 * \brief Method that returns if the Lane can be crossed by a Character.
		 *
		 * \return bool : True (a Lane can be crossed by a Character).
		 */	
	    bool canBeCrossed() override;

	    /**
		 *  shared_ptr<Lane> clone(int posX,int poxY) override;
		 * \brief Prototype method used to instantiate a new Lane object. Change the created Lane position to (posX,posY).
		 *
		 * \return shared_ptr<Lane> the new object created with the prototype.
		 */
	    shared_ptr<Lane> clone(int posX,int poxY) override;

};


#endif