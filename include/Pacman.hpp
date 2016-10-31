#ifndef DEF_PACMAN
#define DEF_PACMAN

#include <SDL2/SDL.h>
#include <Character.hpp>
#include <iostream>


using namespace std;

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

		int requestedDirection_;

	public:	
		Pacman(char*,int, int, int, SDL_Renderer*);
		SDL_Texture* getCharacterTexture() override;
		void destroySDLElements() override;		
		void moveCharacter(GameEngine*, int) override;
		void calculateNextDirection() override;
		void setDirection(int) override;


};


#endif