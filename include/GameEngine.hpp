#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <Character.hpp>
#include <vector>
#include <MapElement.hpp>
#include <memory>
#include <Bonus.hpp>
#include <GhostFactory.hpp>
#include <MapFactory.hpp>


const int sizeSprite = 25;


class GameEngine{

	public:

		GameEngine();
		~GameEngine();		
		void renderCharacter(shared_ptr<Character>);
		void destroyRenderer();
		void moveCharacter(shared_ptr<Character>);
		void moveCharacters();


		void changePacmanDirection(int);
		void createMap(std::vector<std::vector<char>> const& laby);
		void renderMap();
		void clearRenderer();
		void renderPresent();

		shared_ptr<MapElement>  getMapElement(int x, int y);		

		bool checkColision(int x, int y);	
		bool checkColisionSDLRect(SDL_Rect* c1, SDL_Rect* c2);
		int getSizeSprite();	

		void launchNampac(const char*);
		void renderCharacters();

		void renderGameOverMessage();
		void renderPlayerScore();

		void checkAllCharactersColision();

		void checkBonusEating();

		void handleBonus(char);

	private:

		unique_ptr<MapFactory> mapElementFactory_;
		unique_ptr<GhostFactory> ghostFactory_;

		SDL_Window* window_;
		SDL_Renderer* renderer_;		
		shared_ptr<Character> pacman_;

		TTF_Font* fontScoring_;
		TTF_Font* fontGameOver_;
		SDL_Color white_;
		SDL_Color red_;

		SDL_Texture* gameOverTexture_;
		SDL_Surface* gameOverSurface_;
		SDL_Rect gameOverRect_;
		bool gameOver_;

		
		vector<shared_ptr<Character>> ghosts_;						
		
		vector<vector<std::shared_ptr<MapElement>>> mapElements_;

		int randNumber_;	

		int playerScore_;
		SDL_Texture* playerScoreTexture_;
		SDL_Surface* playerScoreSurface_;
		SDL_Rect playerScoreRect_;

		


};


#endif