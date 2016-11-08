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
#include <Bonus.hpp>
#include <GhostFactory.hpp>
#include <MapFactory.hpp>


const int sizeSprite = 25;

/**
 * \file GameEngine.cpp
 * \brief game engine implementation.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 */

class GameEngine{

	public:

		/**
		 * GameEngine();
		 * \brief GameEngine constructor.
		 */
		GameEngine();

		/**
		 * GameEngine();
		 * \brief GameEngine destructor.
		 */
		~GameEngine();

		/**
		 * void renderCharacter(shared_ptr<Character>);
		 * \brief used to dispay a character.
		 *
		 * \param shared_ptr<Character> c: character show.
		 */
		void renderCharacter(shared_ptr<Character> c);
		
		/**
		 * void moveCharacter(shared_ptr<Character>);
		 * \brief used to move a Character.
		 *
		 * \param shared_ptr<Character> c: character move.
		 */
		void moveCharacter(shared_ptr<Character> c);

		/**
		 * void moveCharacters();
		 * \brief used to move all characters.
		 */
		void moveCharacters();

		/**
		 * void changePacmanDirection(int);
		 * \brief used to change pacman's direction.
		 *
		 * \param int d: direction, int between 0 and 3 (0: right, 1: left, 2: up, 3: down)
		 */
		void changePacmanDirection(int d);

		/**
		 * void createMap(std::vector<std::vector<char>> const& laby);
		 * \brief used to create map.
		 *
		 * \param std::vector<std::vector<char>> const& laby: char labyrinth
		 */
		void createMap(std::vector<std::vector<char>> const& laby);

		/**
		 * void renderMap();
		 * \brief used to prepare map to show.
		 */
		void renderMap();

		/**
		 * void clearRenderer();
		 * \brief used to clear the rendrer.
		 */
		void clearRenderer();

		/**
		 * void renderPresent();
		 * \brief used to update the screen.
		 */
		void renderPresent();

		/**
		 * shared_ptr<MapElement> getMapElement(int x, int y);
		 * \brief used to get map element.
		 *
		 * \param int x: x position of map element
		 * \param int y: y position of map element
		 */
		shared_ptr<MapElement> getMapElement(int x, int y);		

		/**
		 * bool checkColision(int x, int y);
		 * \brief used to check if a colision.
		 *
		 * \param int x: x position to check
		 * \param int y: y position to check
		 *	
		 * \return bool: if colision
		 */
		bool checkColision(int x, int y);

		/**
		 * bool checkColisionSDLRect(SDL_Rect* c1, SDL_Rect* c2);
		 * \brief used to check if a colision between characters.
		 *
		 * \param SDL_Rect* c1: SDL_Rect of the first character
		 * \param SDL_Rect* c2: SDL_Rect of the second character
		 *
		 * \return bool: if two character are in colision
		 */
		bool checkColisionSDLRect(SDL_Rect* c1, SDL_Rect* c2);
		
		/**
		 * int getSizeSprite();
		 * \brief used to get size of sprite.
		 *
		 * \return int: size of sprite
		 */
		int getSizeSprite();	

		/**
		 * void launchNampac(const char* nameFile);
		 * \brief used to start the game and to listen keyboard events.
		 *
		 * \param const char* nameFile: file's name of the map
		 */
		void launchNampac(const char* nameFile);

		/**
		 * void renderCharacters();
		 * \brief used to dispay all characters.
		 *
		 */
		void renderCharacters();

		/**
		 * renderGameOverMessage
		 * \brief used to show game over message.
		 *
		 */
		void renderGameOverMessage();
		
		/**
		 * void renderPlayerScore();
		 * \brief used to show the score.
		 *
		 */
		void renderPlayerScore();

		/**
		 * checkAllCharactersColision();
		 * \brief used to determinate what to do when pacman is colision with a ghost
		 *
		 */
		void checkAllCharactersColision();

		/**
		 * void checkBonusEating();
		 * \brief used to check what is the bonus
		 *
		 */
		void checkBonusEating();

		/**
		 * void handleBonus(char b);
		 * \brief used to add a bonus to pacman (decorator)
		 *
		 * \param const char: symbole of bonus
		 */
		void handleBonus(char b);

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