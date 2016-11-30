#ifndef DEF_CHARACTERDECORATOR
#define DEF_CHARACTERDECORATOR

#include <memory>
#include <Character/Character.hpp>

using namespace std;

/**
 * \brief Decorator pattern implementation for the character speed decoration.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Decorator pattern implementation for the Nampac game. A Character can be decored to modify his behaviour during the game (used for the speed modification). Non-modified methods are calling the decorated object's method.
 *
 */


class CharacterDecorator : public Character{

	public:

		/**
		 * CharacterDecorator(shared_ptr<Character> c);
		 * \brief Abstract CharacterDecorator contructor.
		 *		
		 * \param c : the decorated character.
		 */
		CharacterDecorator(shared_ptr<Character> c);

		/**
		 * virtual int getSpeed() override =0;	
		 *
		 * \brief Abstract method : return the modified speed of the decorated character based on his speed (call of his getSpeed method).
		 *
		 * \return int : the modified speed of the decorated character.
		 */
		virtual int getSpeed() override =0; 

		/**
		 * void changePosition(int posX, int posY);
		 * \brief method used to change character's position (call the decorated object method).
		 * \param posX : X position on the map.
		 * \param posY : Y position on the map.
		 */
		void changePosition(int posX,int posY);

		
		/**
		 * int getPosX() override;
		 * \brief definition of the x position getter (call the decorated object method).
		 *
		 * \return int : x position of character.
		 */	
		int getPosX() override;
		
		/**
		 * int getPosY() override;
		 * \brief definition of the y position getter (call the decorated object method).
		 *
		 * \return int : y position of character.
		 */	
		int getPosY() override;
		
		/**
		 * vector<SDL_Texture*> getCharacterTexture() override;
		 * \brief definition of the SDL_Texture getter (call the decorated object method).
		 *
		 * \return vector<SDL_Texture*>: all SDL_Texture of character to render.
		 */	
		vector<SDL_Texture*> getCharacterTexture() override;
		
		/**
		 * SDL_Rect* getTextureRect() override;
		 * \brief definition of the SDL_Rect getter (call the decorated object method).
		 *
		 * \return SDL_Rect*: SDL_Rect* of character to render.
		 */	
		SDL_Rect* getTextureRect() override;
		
		/**
		 * int getDirection() override;
		 * \brief definition of the direction getter (call the decorated object method).
		 *
		 * \return int: Direction of character.
		 */	
		int getDirection() override;
		
		/**
		 * void setDirection(int direction) override;
		 * \brief definition of the direction setter (call the decorated object method).
		 *
		 * \param direction : direction, int between 0 and 3 (0: right, 1: left, 2: up, 3: down)
		 *
		 */	
		void setDirection(int direction) override;
		
		/**
		 * void moveCharacter(GameEngine* g, int speed)=0 override;
		 * \brief abstract method used to move character (call the decorated object method).
		 *
		 * \param g : the game engine.
		 * \param speed : character speed.
		 *
		 */	
		void moveCharacter(GameEngine* g, int speed) override;

		/**
		 * void calculateNextDirection()=0 override;
		 * \brief abstract method used to calculate the next position of character (call the decorated object method).
		 *
		 * \param GameEngine* : the GameEngine.
		 * \param int : the speed of the character (needed because of the link CharacterDecorator / GhostMovementState).
		 */	
		void calculateNextDirection() override;		

		/**
		 *bool canEatGhost() override;
		 * \brief Ask Pacman current state to know if Pacman can eat ghosts or not. Implemented because of CharacterDecorator, return False for a non-Pacman character (call the decorated object method).
		 *
		 */	
		bool canEatGhost() override;

		/**
		 *void setDeathPosition() override;
		 * \brief Set the ghost to his designated death position. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void setDeathPosition() override;

		/**
		 *void setMovementDeadState() override;
		 * \brief Change the movement state of the ghost to a GhostMovementDead. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void setMovementDeadState() override;

		/**
		 *void setMovementAmbushState() override;
		 * \brief Change the movement state of the ghost to a GhostMovementAmbush. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void setMovementAmbushState() override;

		/**
		 *void setMovementStupidState() override;
		 * \brief Change the movement state of the ghost to a GhostMovementStupid. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void setMovementStupidState() override;

		/**
		 *void setMovementUnpredictableState() override;
		 * \brief Change the movement state of the ghost to a GhostMovementUnpredictable. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void setMovementUnpredictableState() override;


		/**
		 *void setMovementUnpredictableState() override;
		 * \brief Change the movement state of the ghost to a GhostMovementChase. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void setMovementChaseState() override;


		/**
		 *void backToClassicState() override;
		 * \brief Change the movement state of the ghost to his classic state (different for all ghosts). Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void backToClassicState() override;

		/**
		 *void askChangeMovementDeadState() override;
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementDeadState. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void askChangeMovementDeadState() override;

		/**
		 *void askChangeMovementAmbushState() override;
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementAmbushState. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void askChangeMovementAmbushState() override;

		/**
		 *void askChangeMovementStupidState() override;
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementStupidState. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void askChangeMovementStupidState() override;


		/**
		 *void askChangeMovementUnpredictableState() override;
		 * \brief Ask to the current state of a ghost if its state can be changed to an GhostMovementUnpredictable. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void askChangeMovementUnpredictableState() override;

		/**
		 *void askChangeMovementChaseState() override;
		 * \brief Ask to the current state of a ghost if its state can be changed to a GhostMovementChaseState. Implemented because of CharacterDecorator, does nothing for a non-ghost character (call the decorated object method).
		 *
		 */	
		void askChangeMovementChaseState() override;

		/**
		 * void askChangeStateHunter() override;
		 * \brief Ask to the current pacman state if its state can be changed to a HunterState. Implemented because of CharacterDecorator, does nothing for a non-Pacman character (call the decorated object method).
		 *
		 */	
		void askChangeStateHunter() override;

		/**
		 *void changeStateHunter() override;
		 * \brief method used to change Pacman's state to Hunter (can eat Ghosts). Implemented because of CharacterDecorator, does nothing for a non-Pacman character (call the decorated object method).
		 *
		 */	
		void changeStateHunter() override;

		/**
		 *void changeStatePrey() override;
		 * \brief method used to change Pacman's state to Prey (can't eat Ghosts). Implemented because of CharacterDecorator, does nothing for a non-Pacman character (call the decorated object method).
		 *
		 */	
		void changeStatePrey() override;



	protected:
		shared_ptr<Character> character_;		

		
};


#endif