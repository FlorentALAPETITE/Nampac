#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <SDL2/SDL.h>
#include <iostream>
#include <Character.hpp>
#include <Pacman.hpp>
#include <vector>
#include <MapElement.hpp>
#include <memory>


class GameEngine{

	public:

		GameEngine();		
		void renderCharacter(Character*);
		void destroyRenderer();
		void moveCharacter(Character*);
		
		void changePacmanDirection(int);
		void createMap(std::vector<std::vector<int>> const& laby);
		void renderMap();
		void clearRenderer();
		void renderPresent();
		
		shared_ptr<MapElement>  getMapElement(int x, int y);
		bool checkColision(int x, int y);		

		void destroySDL();

		void launchNampac(const char*);


	private:

		SDL_Window* window_;
		SDL_Renderer* renderer_;		
		std::unique_ptr<Pacman> pacman_;
					
		
		vector<vector<std::shared_ptr<MapElement>>> mapElements_;		
		


};


#endif