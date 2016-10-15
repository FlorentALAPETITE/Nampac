#ifndef DEF_GHOST
#define DEF_GHOST


#include <Character.hpp>
#include <GhostMovementState.hpp>
#include <GhostMovementChase.hpp>
#include <memory>

using namespace std;


// class GhostMovementState;
// class GhostMovementChase;


class Ghost : public Character{

	public:
		Ghost(char*, int, int, SDL_Renderer*);
		void calculateNextDirection();

	protected:
		shared_ptr<GhostMovementChase> movementChaseState_;
		shared_ptr<GhostMovementState> currentMovementState_;

};


#endif

