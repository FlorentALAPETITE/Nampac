#ifndef DEF_MAPELEMENTFACTORY
#define DEF_MAPELEMENTFACTORY

#include <MapElement/MapElement.hpp>
#include <memory>
#include <SDL2/SDL.h>
#include <Prototype/BonusFactory.hpp>
#include <MapElement/Lane.hpp>
#include <MapElement/Wall.hpp>


using namespace std;

/**
	 * 
	 * \brief MapElement factory class implementation for the Nampac map creation (using a Prototype Pattern).
	 * \author Florent ALAPETITE / Dorian LATOUCHE
	 *
	 * Class that implements the dynamical creation method for the MapElement using the Prototype Pattern. The MapElement factory contains a bonus factory to make bonus creation requests.
	 *
 	*/	

class MapElementFactory {

	public:
		/**		
		 * MapElementFactory(const int sizeSprite, SDL_Renderer* renderer);
		 * \brief MapElementFactory constructor.
		 *
		 * \param sizeSprite : general sprite size (default : 25px).		
		 * \param renderer : unique SDL_Renderer used to render the game.
		
		*/
		MapElementFactory(const int sizeSprite, SDL_Renderer* renderer);

		/**
		 * virtual shared_ptr<MapElement> createMapElement(const char type, const unsigned int c, const unsigned int  l, int& gumNumber);
		 * \brief MapElement creation method using the Prototype pattern. The required MapElement is created using the clone method of the corresponding prototype attribute.
		 *
		 * \param type : type of the required MapElement.
		 * \param c : column position of the MapElement on the map
		 * \param l : line position of the MapElement on the map.
		 * \param gumNumber: pointer to the number of gum bonuses.	
		 * 
		 * \return shared_ptr<MapElement> : pointer to the required MapElement.
		 
		 */
		virtual shared_ptr<MapElement> createMapElement(const char type, const unsigned int c, const unsigned int  l, int& gumNumber);

	protected:
		unique_ptr<BonusFactory> bonusFactory_;

		shared_ptr<Lane> lanePrototype_;
		shared_ptr<Wall> wallPrototype_;
		int sizeSprite_;

};


#endif