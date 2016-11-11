#ifndef DEF_PACMAN
#define DEF_PACMAN

#include <SDL2/SDL.h>
#include <Character/Character.hpp>
#include <PacmanState/PacmanState.hpp>
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

		SDL_Texture* hunterParticleTexture_;
		SDL_Surface* hunterParticleSurface_;

		int requestedDirection_;

		shared_ptr<PacmanState> currentState_;
		shared_ptr<PacmanState> hunterState_;
		shared_ptr<PacmanState> preyState_;

	public:	
		Pacman(char*,int, int, int, SDL_Renderer*);
		~Pacman();
		vector<SDL_Texture*> getCharacterTexture() override;
		

		void moveCharacter(GameEngine*, int) override;
		void calculateNextDirection() override;
		void setDirection(int) override;

		void changeStateHunter() override;
		void changeStatePrey();
		bool canEatGhost() override;


};


#endif