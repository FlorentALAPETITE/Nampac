#ifndef DEF_PREYSTATE
#define DEF_PREYSTATE

#include <SDL2/SDL.h>
#include <PacmanState.hpp>

using namespace std;

class PreyState: public PacmanState {

	public:
		PreyState(Pacman* pacman);		
		bool canEatGhost() override;
		void decrementRemainingMovement() override;
		void addRemainingMovement(int m) override;
		void changeStateHunter() override;
		void changeStatePrey() override;


};

#endif