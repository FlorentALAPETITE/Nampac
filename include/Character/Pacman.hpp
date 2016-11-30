#ifndef DEF_PACMAN
#define DEF_PACMAN

#include <SDL2/SDL.h>
#include <Character/Character.hpp>
#include <PacmanState/PacmanState.hpp>
#include <iostream>


using namespace std;

/**
 * \brief Pacman implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman implementation for the Nampac game. The Pacman is controlled by the human player using arrow keys.
 *
 */


class Pacman : public Character{

	private:
		unsigned int open_;
		SDL_Texture* characterTextureOpenTop_;
		SDL_Surface* characterSurfaceOpenTop_;

		SDL_Texture* characterTextureOpenRight_;
		SDL_Surface* characterSurfaceOpenRight_;

		SDL_Texture* characterTextureOpenBot_;
		SDL_Surface* characterSurfaceOpenBot_;

		SDL_Texture* characterTextureOpenLeft_;
		SDL_Surface* characterSurfaceOpenLeft_;

		SDL_Texture* hunterParticleTexture_;
		SDL_Surface* hunterParticleSurface_;

		int requestedDirection_;

		shared_ptr<PacmanState> currentState_;
		shared_ptr<PacmanState> hunterState_;
		shared_ptr<PacmanState> preyState_;

	public:	
		/**
		 * Pacman(char* sl,int s, int posX, int posY, SDL_Renderer* renderer);
		 * \brief Pacman constructor.
		 *
		 * \param sl : path for the Pacman sprite location.
		 * \param s : speed of the Pacman. 
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.		
		 */
		Pacman(char* sl,int s, int posX, int posY, SDL_Renderer* renderer);

		/**
		* ~Pacman();
		* \brief Pacman specific destructor for the special SDL graphical elements.
		*/		
		~Pacman();

		/**
		* vector<SDL_Texture*> getCharacterTexture() override;		
		* \brief Textures getter for the game rendering.
		* \return vector<SDL_Texture*> : vector of all graphical elements needed to render the Pacman.
		*/	
		vector<SDL_Texture*> getCharacterTexture() override;
		
		/**
		* void moveCharacter(GameEngine* g, int speed) override;
		*	
		* \brief Pacman deplacement method.
		* \param GameEngine* : the GameEngine.
		* \param int : the speed of the character (needed because of the link CharacterDecorator / GhostMovementState).	
		*/
		void moveCharacter(GameEngine* g, int speed) override;

		/**
		*  void calculateNextDirection() override;
		*	
		* \brief Character direction calculation (does nothing for the Pacman because it is controlled by a human player).		
		*/
		void calculateNextDirection() override;

		/**
		*  void setDirection(int) override;
		*
		* \param direction : the requested direction
		* \brief Change the Pacman requested direction : the true direction will be modified next time a movement to this direction will be possible.
		*/
		void setDirection(int direction) override;

		/**
		* void changeStateHunter() override;
		*	
		* \brief PacmanState setter : set the current Pacman state to a HunterState.		
		*/
		void changeStateHunter() override;

		/**
		* void changeStatePrey();
		*	
		* \brief PacmanState setter : set the current Pacman state to a PreyState.		
		*/
		void changeStatePrey();

		/**
		* void askChangeStateHunter() override;
		*	
		* \brief Ask the current Pacman state if the state can be modified to a HunterState.	
		*/
		void askChangeStateHunter() override;

		/**
		* bool canEatGhost() override;
		*	
		* \brief Ask the current Pacman state if the Pacman can eat ghosts.
		* \return bool : true if Pacman can eat ghosts (HunterState), false else.
		*/
		bool canEatGhost() override;



};


#endif