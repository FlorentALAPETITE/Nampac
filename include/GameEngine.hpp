#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <Character.hpp>
#include <Pacman.hpp>
#include <vector>
#include <MapElement.hpp>
#include <memory>
#include <Ghost.hpp>
#include <Bonus.hpp>
#include <GhostFactory.hpp>
#include <MapElementFactory.hpp>


const int sizeSprite = 25;


class GameEngine{

	public:

		GameEngine();		
		void renderCharacter(Character*);
		void destroyRenderer();
		void moveCharacter(Character*);
		void moveCharacters();


		void changePacmanDirection(int);
		void createMap(std::vector<std::vector<char>> const& laby);
		void renderMap();
		void clearRenderer();
		void renderPresent();

		shared_ptr<MapElement>  getMapElement(int x, int y);		

		bool checkColision(int x, int y);	
		bool checkColisionCharacters(SDL_Rect* c1, SDL_Rect* c2);
		int getSizeSprite();	


		void destroySDL();
		void launchNampac(const char*);
		void renderCharacters();

		void renderGameOverMessage();
		void renderPlayerScore();

		void checkAllCharactersColision();

	private:

		unique_ptr<MapElementFactory> mapElementFactory_;
		unique_ptr<GhostFactory> ghostFactory_;

		SDL_Window* window_;
		SDL_Renderer* renderer_;		
		std::unique_ptr<Pacman> pacman_;

		TTF_Font* fontScoring_;
		TTF_Font* fontGameOver_;
		SDL_Color white_;
		SDL_Color red_;

		SDL_Texture* gameOverTexture_;
		SDL_Surface* gameOverSurface_;
		SDL_Rect gameOverRect_;
		bool gameOver_;

		
		vector<std::unique_ptr<Ghost>> ghosts_;						
		
		vector<vector<std::shared_ptr<MapElement>>> mapElements_;

		int randNumber_;	

		int playerScore_;
		SDL_Texture* playerScoreTexture_;
		SDL_Surface* playerScoreSurface_;
		SDL_Rect playerScoreRect_;

		


};


#endif