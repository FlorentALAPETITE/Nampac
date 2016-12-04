#ifndef DEF_WALL
#define DEF_WALL

#include <MapElement/MapElement.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete Wall implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete class that implements Wall behaviour. A Wall cannot contain a bonus and cannot be crossed by a Character.
 *
 */	

class Wall : public MapElement, public Prototype<Wall>{	

	public:		
		/**
		 * Wall(int posX, int posY,SDL_Renderer* renderer);
		 *
		 * \brief Wall constructor.
		 *		
		 * \param posX : X position of the Wall on the map.
		 * \param posY : Y position of the Wall on the map.
		 * \param renderer :  unique SDL_Renderer used to render the game.
		 */
		Wall(int posX, int posY,SDL_Renderer* renderer);

		/**
		 * Wall(const Wall &wall);	
		 * \brief Wall copy contructor.
		 *		
		 * \param wall : existing Wall object pointer.
		 */	
		Wall(const Wall &wall);	

		/**
		 * bool canBeCrossed() override;
		 * \brief Method that returns if the Wall can be crossed by a Character.
		 *
		 * \return bool : False (a Wall cannot be crossed by a Character).
		 */	
	    bool canBeCrossed() override;

	    /**
		 *  shared_ptr<Wall> clone(int posX,int poxY) override;
		 * \brief Prototype method used to instantiate a new Wall object. Change the created Wall position to (posX,posY).
		 *
		 * \return shared_ptr<Wall> the new object created with the prototype.
		 */
	    shared_ptr<Wall> clone(int posX,int poxY) override;

	    /**
		 * void setBonus(shared_ptr<Bonus> b) override; 
		 * \brief Bonus setter implementation for the wall -> does nothing because a Wall cannot contain a bonus.
		 *	
		 * \param b : the bonus to stock in the Wall.
		 */
	    void setBonus(shared_ptr<Bonus> b) override;   
};


#endif