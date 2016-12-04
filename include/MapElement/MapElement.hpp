#ifndef DEF_MAPELEMENT
#define DEF_MAPELEMENT

#include <SDL2/SDL.h>
#include <Bonus/Bonus.hpp>
#include <memory>

using namespace std;

/**
 * \brief Abstract MapElement class implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Abstract class that implements map element basic behaviour.
 *
 */	

class MapElement{
	protected:
		SDL_Texture* mapElementTexture_;
		SDL_Surface* mapElementSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;			
		shared_ptr<Bonus> bonus_;
		char* spriteLocation_;

	public:

		/**
		 * MapElement(char* sl,int posX,int posY,SDL_Renderer* renderer);
		 *
		 * \brief Abstract MapElement constructor.
		 *
		 * \param sl : path ot the character sprite.
		 * \param posX : X position of the MapElement on the map.
		 * \param posY : Y position of the MapElement on the map.
		 * \param renderer :  unique SDL_Renderer used to render the game.
		 */
		MapElement(char* sl,int posX,int posY,SDL_Renderer* renderer);

		/**
		 * MapElement(const MapElement &mapElement);
		 * \brief Abstract MapElement copy contructor.
		 *		
		 * \param mapElement : existing MapElement pointer.
		 */
		MapElement(const MapElement &mapElement);

		/**
		 * ~MapElement();
		 * \brief Abstract MapElement destructor.
		 */
		~MapElement();

		/**
		 * SDL_Rect* getTextureRect();	
		 * \brief Definition of the SDL_Rect getter.
		 *
		 * \return SDL_Rect*: SDL_Rect* of the MapElement to render.
		 */	
		SDL_Rect* getTextureRect();	

		/**
		 * SDL_Texture* getMapElementTexture();
		 * \brief Definition of the SDL_Texture getter.
		 *
		 * \return SDL_Texture*: SDL_Texture* of the MapElement to render.
		 */	
		SDL_Texture* getMapElementTexture();

		/**
		 * virtual bool canBeCrossed()=0;	
		 * \brief Virtual method that returns if the MapElement can be crossed by a Character.
		 *
		 * \return bool : True if the MapElement can be crossed, else then.
		 */	
		virtual bool canBeCrossed()=0;	

		/**
		 * shared_ptr<Bonus> getBonus();
		 * \brief Getter implementation for the bonus stocked in the MapElement.
		 *
		 * \return shared_ptr<Bonus> : smart pointer to the stocked bonus.
		 */	
		shared_ptr<Bonus> getBonus();

		/**
		 * void eatBonus();
		 * \brief Set the bonus pointer of the MapElement to nullptr when called (bonus eaten).
		 *	
		 */
		void eatBonus();

		/**
		 * virtual void setBonus(shared_ptr<Bonus> b);
		 * \brief Bonus setter implementation.
		 *	
		 * \param b : the bonus to stock in the MapElement.
		 */
		virtual void setBonus(shared_ptr<Bonus> b);

		/**
		 * void setPosition(int newPosX, int newPosY);
		 * \brief Position setter implementation.
		 *	
		 * \param newPosX : the new X position of the MapElement.
		 * \param newPosY : the new Y position of the MapElement.
		 */
		void setPosition(int newPosX, int newPosY);

};


#endif