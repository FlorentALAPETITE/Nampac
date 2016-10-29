#ifndef DEF_GHOSTMOVEMENTDEAD
#define DEF_GHOSTMOVEMENTDEAD

#include <GhostMovementState.hpp>

using namespace std;

class GhostMovementDead : public GhostMovementState {

	public:
		GhostMovementDead(Ghost *);
		void calculateDirection() override;
		void moveCharacter(GameEngine*) override;
		
};


#endif
