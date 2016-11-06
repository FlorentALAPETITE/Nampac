#ifndef DEF_GHOSTMOVEMENTDEAD
#define DEF_GHOSTMOVEMENTDEAD

#include <GhostMovementState.hpp>

using namespace std;

class GhostMovementDead : public GhostMovementState {

	public:
		GhostMovementDead(Ghost *);
		void calculateDirection() override;
		void moveCharacter(GameEngine*, int speed) override;
		void setMovementDeadState() override;
		void setMovementAmbushState() override;
		void setMovementStupidState() override;
		void setMovementUnpredictableState() override;
		void setMovementChaseState() override;
		
};


#endif
