#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <SDL2/SDL.h>
#include <iostream>
#include <Character.hpp>
#include <Pacman.hpp>

class GameEngine{

	public:

		GameEngine();
		SDL_Window* getWindow();	
		void setBackgroundBlack();
		void renderCharacter(Character*);
		void destroyRenderer();
		void moveCharacter(Character*);
		Pacman* getPacman();
		void changePacmanDirection(int);



	private:

		SDL_Window* window_;
		SDL_Renderer* renderer_;
		Pacman* pacman_;
		


};


#endif