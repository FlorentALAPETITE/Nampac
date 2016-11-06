#ifndef DEF_GHOSTMOVEMENTSTATE
#define DEF_GHOSTMOVEMENTSTATE

#include <memory>

using namespace std;

class Ghost;

class GameEngine;

class GhostMovementState {

	public:
		GhostMovementState(Ghost*);
		virtual void calculateDirection() = 0;
		virtual void moveCharacter(GameEngine*, int);
		virtual void setMovementDeadState();
		virtual void setMovementAmbushState();
		virtual void setMovementStupidState();
		virtual void setMovementUnpredictableState();
		virtual void setMovementChaseState();
		void backToClassicState();
		void setLifeTime(int);

	protected:
		Ghost* ghost_;
		int nextDirectionCalc_;
		int stateLifeTime_;

		
};


#endif

