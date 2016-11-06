#ifndef DEF_HUNTERSTATE
#define DEF_HUNTERSTATE

#include <SDL2/SDL.h>
#include <PacmanState.hpp>

using namespace std;

class HunterState: public PacmanState {

	public:
		HunterState(Pacman* pacman);		
		bool canEatGhost() override;
		void decrementRemainingMovement() override;
		void addRemainingMovement(int m) override;
		void changeStateHunter() override;
		void changeStatePrey() override;

	protected:
		int remainingMovement_;

};

#endif