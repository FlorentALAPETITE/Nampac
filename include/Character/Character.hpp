#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class GameEngine;
/**
 * \brief Abstract character class implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Abstract class that implements basics characters.
 *
 */	
class Character{

	public:
		/**
		 * Character(char* sl, int s, int posX, int posY, SDL_Renderer* renderer);	
		 * \brief Abstract character creation method.
		 *
		 * \param sl : char* name of the sprite to use for illustrate character
		 * \param s : used to set the speed of character.
		 * \param posX : line position of the MapElement that require the character.
		 * \param posY : line position of the MapElement that require the character.
		 * \param renderer :  unique SDL_Renderer used to render the game.
		 */
		Character(char* sl, int s, int posX, int posY, SDL_Renderer* renderer);	
		
		/**
		 * Character();	
		 * \brief Abstract character creation method (empty constructor).
		 */
		Character();	

		/**
		 * ~Character();	
		 * \brief Abstract character destructor method.
		 */
		~Character();

		/**
		 * int getSpeed();
		 * \brief definition of the speed getter.
		 *
		 * \return speed :character's speed.
		 */	
		virtual int getSpeed();

		/**
		 * void changePosition(int posX, int posY);
		 * \brief method used to change character's position.
		 * \param posX : X position on the map.
		 * \param posY : Y position on the map.
		 */
		virtual void changePosition(int posX,int posY);

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
		 * \return vector<SDL_Texture*>: all SDL_Texture of character to render.
		 */	
		virtual vector<SDL_Texture*> getCharacterTexture();
		
		/**
		 * SDL_Rect* getTextureRect();
		 * \brief definition of the SDL_Rect getter.
		 *
		 * \return SDL_Rect*: SDL_Rect* of character to render.
		 */	
		virtual SDL_Rect* getTextureRect();
		
		/**
		 * int getDirection();
		 * \brief definition of the direction getter.
		 *
		 * \return int: Direction of character.
		 */	
		virtual int getDirection();
		
		/**
		 * void setDirection(int direction);
		 * \brief definition of the direction setter.
		 *
		 * \param direction : direction, int between 0 and 3
		 *
		 */	
		virtual void setDirection(int direction);
		
		/**
		 *virtual void moveCharacter(GameEngine* g, int speed)=0;
		 * \brief abstract method used to move character.
		 *
		 * \param g : the game engine.
		 * \param speed : character speed.
		 *
		 */	
		virtual void moveCharacter(GameEngine* g, int speed)=0;

		/**
		 *virtual void calculateNextDirection()=0;
		 * \brief abstract method used to calculate the next position of character.
		 *
		 */	
		virtual void calculateNextDirection()=0;


		/**
		 *virtual void changeStateHunter();
		 * \brief method used to change Pacman's state to Hunter (can eat Ghosts). Implemented because of CharacterDecorator, does nothing for a non-Pacman character.
		 *
		 */	
		virtual void changeStateHunter();

		/**
		 *virtual bool canEatGhost();
		 * \brief Ask Pacman current state to know if Pacman can eat ghosts or not. Implemented because of CharacterDecorator, return False for a non-Pacman character.
		 *
		 */	
		virtual bool canEatGhost();

		/**
		 *virtual void setDeathPosition();
		 * \brief Set the ghost to his designated death position. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void setDeathPosition();

		/**
		 *virtual void setMovementDeadState();
		 * \brief Change the movement state of the ghost to a GhostMovementDead. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void setMovementDeadState();

		/**
		 *virtual void setMovementAmbushState();
		 * \brief Change the movement state of the ghost to a GhostMovementAmbush. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void setMovementAmbushState();

		/**
		 *virtual void setMovementStupidState();
		 * \brief Change the movement state of the ghost to a GhostMovementStupid. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void setMovementStupidState();

		/**
		 *virtual void setMovementUnpredictableState();
		 * \brief Change the movement state of the ghost to a GhostMovementUnpredictable. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void setMovementUnpredictableState();


		/**
		 *virtual void setMovementUnpredictableState();
		 * \brief Change the movement state of the ghost to a GhostMovementChase. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void setMovementChaseState();


		/**
		 *virtual void backToClassicState();
		 * \brief Change the movement state of the ghost to his classic state (different for all ghosts). Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void backToClassicState();

		/**
		 *virtual void askChangeMovementDeadState();
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementDeadState. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void askChangeMovementDeadState();

		/**
		 *virtual void askChangeMovementAmbushState();
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementAmbushState. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void askChangeMovementAmbushState();

		/**
		 *virtual void askChangeMovementStupidState();
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementStupidState. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void askChangeMovementStupidState();


		/**
		 *virtual void askChangeMovementUnpredictableState();
		 * \brief Ask to the current state of a ghost if its state can be changed to an GhostMovementUnpredictable. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void askChangeMovementUnpredictableState();

		/**
		 *virtual void askChangeMovementChaseState();
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementChaseState. Implemented because of CharacterDecorator, does nothing for a non-ghost character.
		 *
		 */	
		virtual void askChangeMovementChaseState();


	protected:
		
		int speed_;
		SDL_Texture* characterTexture_;
		SDL_Surface* characterSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;
		int direction_;


};


#endif