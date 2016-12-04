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
		 * Character(char* sl, int s, int posX, int posY,SDL_Renderer* renderer);	
		 * \brief Abstract character creation method.
		 *
		 * \param sl : path ot the character sprite.
		 * \param s : used to set the speed of character.
		 * \param posX : X position of the character on the map.
		 * \param posY : Y position of the character on the map.
		 * \param renderer :  unique SDL_Renderer used to render the game.
		 */
		Character(char* sl, int s, int posX, int posY,SDL_Renderer* renderer);	

		/**
		 * Character(const Character &character);
		 * \brief Abstract character copy contructor.
		 *		
		 * \param character : existing character pointer.
		 */
		Character(const Character &character);

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
		 * virtual int getSpeed();
		 * \brief Definition of the speed getter.
		 *
		 * \return speed :character's speed.
		 */	
		virtual int getSpeed();

		/**
		 * virtual void changePosition(int posX, int posY);
		 * \brief Method used to change character's position.
		 * \param posX : X position on the map.
		 * \param posY : Y position on the map.
		 */
		virtual void changePosition(int posX,int posY);


		/**
		 * virtual int getPosX();
		 * \brief Definition of the x position getter.
		 *
		 * \return int : x position of character.
		 */	
		virtual int getPosX();
		
		/**
		 * virtual int getPosY();
		 * \brief Definition of the y position getter.
		 *
		 * \return int : y position of character.
		 */	
		virtual int getPosY();
		
		/**
		 * virtual vector<SDL_Texture*> getCharacterTexture();
		 * \brief Definition of the SDL_Texture getter.
		 *
		 * \return vector<SDL_Texture*>: all SDL_Texture of character to render.
		 */	
		virtual vector<SDL_Texture*> getCharacterTexture();
		
		/**
		 * virtual SDL_Rect* getTextureRect();
		 * \brief Definition of the SDL_Rect getter.
		 *
		 * \return SDL_Rect*: SDL_Rect* of the character to render.
		 */	
		virtual SDL_Rect* getTextureRect();
		
		/**
		 * virtual int getDirection();
		 * \brief Definition of the direction getter.
		 *
		 * \return int: Direction of character.
		 */	
		virtual int getDirection();
		
		/**
		 * virtual void setDirection(int direction);
		 * \brief Definition of the direction setter.
		 *
		 * \param direction : direction, int between 0 and 3 (0: right, 1: left, 2: up, 3: down)
		 *
		 */	
		virtual void setDirection(int direction);
		
		/**
		 * virtual void moveCharacter(GameEngine* g, int speed)=0;
		 * \brief Abstract method used to move character.
		 *
		 * \param g : the game engine.
		 * \param speed : character speed.
		 *
		 */	
		virtual void moveCharacter(GameEngine* g, int speed)=0;

		/**
		 * virtual void calculateNextDirection()=0;
		 * \brief Abstract method used to calculate the next position of character.
		 *
		 * \param GameEngine* : the GameEngine.
		 * \param int : the speed of the character (needed because of the link CharacterDecorator / GhostMovementState).
		 */	
		virtual void calculateNextDirection()=0;


	
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

		/**
		 *virtual void askChangeStateHunter();
		 * \brief Ask to the current pacman state if its state can be changed to a HunterState. Implemented because of CharacterDecorator, does nothing for a non-Pacman character.
		 *
		 */	
		virtual void askChangeStateHunter();

		/**
		 *virtual void changeStateHunter();
		 * \brief method used to change Pacman's state to Hunter (can eat Ghosts). Implemented because of CharacterDecorator, does nothing for a non-Pacman character.
		 *
		 */	
		virtual void changeStateHunter();

		/**
		 *virtual void changeStatePrey();
		 * \brief method used to change Pacman's state to Prey (can't eat Ghosts). Implemented because of CharacterDecorator, does nothing for a non-Pacman character.
		 *
		 */	
		virtual void changeStatePrey();


	protected:
		
		int speed_;
		SDL_Texture* characterTexture_;
		SDL_Surface* characterSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;
		int direction_;


};


#endif