#ifndef DEF_PACMANSTATE
#define DEF_PACMANSTATE

#include <SDL2/SDL.h>

using namespace std;	


class Pacman;

class PacmanState {

	public:
		PacmanState(Pacman* pacman);
		virtual bool canEatGhost() = 0;
		virtual void decrementRemainingMovement()=0;
		virtual void addRemainingMovement(int m)=0;
		virtual void changeStatePrey()=0;
		virtual void changeStateHunter()=0;
		

	protected:
		Pacman* pacman_;		
		

};

#endif