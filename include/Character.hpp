#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class GameEngine;
/**
 * \file Character.cpp
 * \brief Abstract character class implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Abstract class that implements basics characters.
 *
 */	
class Character{

	public:
		/**
		 * Character(char* , int , int , int posY,SDL_Renderer*);	
		 * \brief Abstract character creation method.
		 *
		 * \param sl : char* name of the sprite to use for illustrate character
		 * \param s : used to set the speed of character.
		 * \param posX : line position of the MapElement that require the character.
		 * \param posY : line position of the MapElement that require the character.
		 * \param renderer :  unique SDL_Renderer used to render the game..
		 */
		Character(char*, int, int, int, SDL_Renderer*);	
		
		/**
		 * Character();	
		 * \brief abstract chracter creation method.
		 */
		Character();	

		/**
		 * ~Character();	
		 * \brief abstract character destroyer method.
		 */
		~Character();

		/**
		 * int getSpeed();
		 * \brief definition of the speed getter.
		 *
		 * \return int : number of character's speed.
		 */	
		virtual int getSpeed();

		/**
		 * void changePosition(int, int);
		 * \brief methode used to change character's position.
		 */
		virtual void changePosition(int,int);

		/**
		 * int getPosX();
		 * \brief definition of the x position getter.
		 *
		 * \return int : x position of character.
		 */	
		virtual int getPosX();
		
		/**
		 * int getPosY();
		 * \brief definition of the y position getter.
		 *
		 * \return int : y position of character.
		 */	
		virtual int getPosY();
		
		/**
		 * vector<SDL_Texture*> getCharacterTexture();
		 * \brief definition of the SDL_Texture getter.
		 *
		 * \return vector<SDL_Texture*>: all SDL_Texture of character
		 */	
		virtual vector<SDL_Texture*> getCharacterTexture();
		
		/**
		 * SDL_Rect* getTextureRect();
		 * \brief definition of the SDL_Rect getter.
		 *
		 * \return SDL_Rect*: SDL_Rect* of character
		 */	
		virtual SDL_Rect* getTextureRect();
		
		/**
		 * int getDirection();
		 * \brief definition of the direction getter.
		 *
		 * \return int: direction of character
		 */	
		virtual int getDirection();
		
		/**
		 * void setDirection(int);
		 * \brief definition of the direction setter.
		 *
		 * \param int : int direction, between 0 and 3
		 *
		 */	
		virtual void setDirection(int);
		
		/**
		 *virtual void moveCharacter()=0;
		 * \brief abstract method used to move character.
		 *
		 * \param GameEngine* : the game engine
		 * \param int : speed
		 *
		 */	
		virtual void moveCharacter(GameEngine*, int)=0;

		/**
		 *virtual void calculateNextDirection()=0;
		 * \brief abstract method used to calculate the next position of character.
		 *
		 */	
		virtual void calculateNextDirection()=0;
		
		/**
		 *virtual void changeStateHunter();
		 * \brief abstract method used to change state of pacman.
		 *
		 */	
		virtual void changeStateHunter();


	protected:
		
		int speed_;
		SDL_Texture* characterTexture_;
		SDL_Surface* characterSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;
		int direction_;


};


#endif