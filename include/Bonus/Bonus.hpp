#ifndef DEF_BONUS
#define DEF_BONUS

#include <SDL2/SDL.h>

using namespace std;

/**
 * \file Bonus.cpp
 * \brief Abstract bonus class implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Abstract class that implements basic behaviour for the bonuses.
 *
 */	
class Bonus{
	public:
		/**
		 * Bonus(SDL_Renderer* renderer, int posX, int posY, int size,const char * spriteLocation);
		 * \brief Abstract Bonus constructor.
		 *
		 * \param renderer : unique SDL_Renderer used to render the game.
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param size : bonus size (in pixel).
		 * \param spriteLocation : path for the sprite location.
		 */
		Bonus(SDL_Renderer* renderer, int posX, int posY, int size,char * spriteLocation);
		
		/**
		 * Bonus(const Bonus &bonus);
		 * \param bonus : bonus to copy;
		*/
		Bonus(const Bonus &bonus);

		/**
		 * ~Bonus();
		 * \brief Bonus destructor.
		 *		
		 */
		~Bonus();

		/**
		 * SDL_Rect* getTextureRect();
		 * \brief SDL_Rect getter;
		 *
		 * \return SDL_Rect pointer : SDL specific struct that contains size and position of the graphical element.
		 */
		SDL_Rect* getTextureRect();

		/**
		 * void setPosition(int posX, int posY);
		 * \brief method used to change bonus' position.
		 * \param posX : X position on the map.
		 * \param posY : Y position on the map.
		 */
		void setPosition(int posX,int posY);

		/**
		 * SDL_Texture* getTexture();
		 * \brief SDL_Texture getter;
		 *
		 * \return SDL_Texture pointer : SDL specific struct that contains texture pixel data for the rendering of the graphical element.
		 */
		SDL_Texture* getTexture();

		/**
		 * virtual int getPoint()=0;
		 * \brief Abstract definition of the point getter.
		 *
		 * \return int : number of point given by the bonus to the player.
		 */
		virtual int getPoint()=0;

		/**
		 * virtual char getBonusType()=0;
		 * \brief Abstract definition of the bonus type getter.
		 *
		 * \return char : type of the bonus.
		 */
		virtual char getBonusType()=0;

		
	protected:
		SDL_Texture* bonusTexture_;
		SDL_Surface* bonusSurface_;
		SDL_Rect bonusTextureRect_;
		SDL_Renderer* renderer_;

		char* spriteLocation_;

};

#endif