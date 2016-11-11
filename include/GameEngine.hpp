#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <Character/Character.hpp>
#include <vector>
#include <MapElement/MapElement.hpp>
#include <memory>
#include <Bonus/Bonus.hpp>
#include <Prototype/GhostFactory.hpp>
#include <Prototype/MapFactory.hpp>


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
		 * \brief Used to dispay a character.
		 *
		 * \param shared_ptr<Character> c: character show.
		 */
		void renderCharacter(shared_ptr<Character> c);
		
		/**
		 * void moveCharacter(shared_ptr<Character>);
		 * \brief Used to move a Character.
		 *
		 * \param shared_ptr<Character> c: character move.
		 */
		void moveCharacter(shared_ptr<Character> c);

		/**
		 * void moveCharacters();
		 * \brief Used to move all characters.
		 */
		void moveCharacters();

		/**
		 * void changePacmanDirection(int);
		 * \brief Used to change pacman's direction.
		 *
		 * \param int d: direction, int between 0 and 3 (0: right, 1: left, 2: up, 3: down)
		 */
		void changePacmanDirection(int d);

		/**
		 * void createMap(std::vector<std::vector<char>> const& laby);
		 * \brief Used to create map.
		 *
		 * \param std::vector<std::vector<char>> const& laby: char labyrinth
		 */
		void createMap(std::vector<std::vector<char>> const& laby);

		/**
		 * void renderMap();
		 * \brief Used to prepare map to show.
		 */
		void renderMap();

		/**
		 * void clearRenderer();
		 * \brief Used to clear the rendrer.
		 */
		void clearRenderer();

		/**
		 * void renderPresent();
		 * \brief Used to update the screen.
		 */
		void renderPresent();

		/**
		 * shared_ptr<MapElement> getMapElement(int x, int y);
		 * \brief Used to get map element.
		 *
		 * \param int x: x position of map element
		 * \param int y: y position of map element
		 */
		shared_ptr<MapElement> getMapElement(int x, int y);		

		/**
		 * bool checkColision(int x, int y);
		 * \brief Used to check if a colision.
		 *
		 * \param int x: x position to check
		 * \param int y: y position to check
		 *	
		 * \return bool: if colision
		 */
		bool checkColision(int x, int y);

		/**
		 * bool checkColisionSDLRect(SDL_Rect* c1, SDL_Rect* c2);
		 * \brief Used to check if a colision between characters.
		 *
		 * \param SDL_Rect* c1: SDL_Rect of the first character
		 * \param SDL_Rect* c2: SDL_Rect of the second character
		 *
		 * \return bool: if two character are in colision
		 */
		bool checkColisionSDLRect(SDL_Rect* c1, SDL_Rect* c2);
		
		/**
		 * int getSizeSprite();
		 * \brief Used to get size of sprite.
		 *
		 * \return int: size of sprite
		 */
		int getSizeSprite();	

		/**
		 * void launchNampac(const char* nameFile);
		 * \brief Used to start the game and to listen keyboard events.
		 *
		 * \param const char* nameFile: file's name of the map
		 */
		void launchNampac(const char* nameFile);

		/**
		 * void renderCharacters();
		 * \brief Used to dispay all characters.
		 *
		 */
		void renderCharacters();

		/**
		 * renderGameOverMessage
		 * \brief Used to show an end game message.
		 *	
		 * \param message : message to render.
		 * \param color : color of the massage to render.
		 */
		void renderEndGameMessage(const char* message, SDL_Color color);
		
		/**
		 * void renderPlayerScore();
		 * \brief Used to show the score.
		 *
		 */
		void renderPlayerScore();

		/**
		 * checkAllCharactersColision();
		 * \brief Used to determinate what to do when pacman is colision with a ghost.
		 *
		 */
		void checkAllCharactersColision();

		/**
		 * void checkBonusEating();
		 * \brief Used to check what is the bonus that Pacman ate.
		 *
		 */
		void checkBonusEating();

		/**
		 * void handleBonus(char b);
		 * \brief Handle the reaction of the bonus that Pacman ate.
		 *
		 * \param const char: symbole of bonus
		 */
		void handleBonus(char b);

		/**
		 * void checkVictory();
		 * \brief Used to check if the player won (no gum remaining).
		 *
		 */
		void checkVictory();

	private:

		unique_ptr<MapFactory> mapElementFactory_;
		unique_ptr<GhostFactory> ghostFactory_;

		SDL_Window* window_;
		SDL_Renderer* renderer_;		
		shared_ptr<Character> pacman_;

		TTF_Font* fontScoring_;
		TTF_Font* fontEndGame_;
		SDL_Color white_;
		SDL_Color red_;
		SDL_Color green_;

		SDL_Texture* endGameTexture_;
		SDL_Surface* endGameSurface_;
		SDL_Rect endGameRect_;
		bool gameOver_;
		bool victory_;

		
		vector<shared_ptr<Character>> ghosts_;						
		
		vector<vector<std::shared_ptr<MapElement>>> mapElements_;

		int randNumber_;	

		int playerScore_;
		SDL_Texture* playerScoreTexture_;
		SDL_Surface* playerScoreSurface_;
		SDL_Rect playerScoreRect_;

		int gumNumber_;
		


};


#endif