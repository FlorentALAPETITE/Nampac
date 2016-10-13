#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <SDL2/SDL.h>
#include <iostream>
#include <Character.hpp>
#include <Pacman.hpp>
#include <vector>
#include <MapElement.hpp>

class GameEngine{

	public:

		GameEngine();
		SDL_Window* getWindow();		
		void renderCharacter(Character*);
		void destroyRenderer();
		void moveCharacter(Character*);
		Pacman* getPacman();
		void changePacmanDirection(int);
		void createMap(std::vector<std::vector<int>> const& laby);
		void renderMap();
		void clearRenderer();
		void renderPresent();
		
		MapElement* getMapElement(int x, int y);
		bool checkColision(int x, int y);	
		bool checkColisionCaracters(SDL_Rect* c1, SDL_Rect* c2);
		int getSizeSprite();

		void destroySDL();


	private:

		SDL_Window* window_;
		SDL_Renderer* renderer_;
		SDL_Renderer* mapRenderer_;
		Pacman* pacman_;
		int sizeSprite = 25;
		vector<vector<MapElement*>> mapElements_;		
		


};


#endif