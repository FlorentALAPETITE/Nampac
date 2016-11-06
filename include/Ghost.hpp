#ifndef DEF_GHOST
#define DEF_GHOST

#include <Character.hpp>
#include <GhostMovementState.hpp>
#include <memory>

using namespace std;



class Ghost : public Character{

	public:
		Ghost(char*, int, int, SDL_Renderer*);
		void calculateNextDirection() override;
		void moveCharacter(GameEngine*,int) override;

	protected:
		shared_ptr<GhostMovementState> currentMovementState_;

		shared_ptr<GhostMovementState> movementChaseState_;		
		shared_ptr<GhostMovementState> movementAmbushState_;
		shared_ptr<GhostMovementState> movementStupidState_;
		shared_ptr<GhostMovementState> movementUnpredictableState_;
		shared_ptr<GhostMovementState> movementDeadState_;		

};


#endif

