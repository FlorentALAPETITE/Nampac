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

	protected:
		Ghost* ghost_;
		int nextDirectionCalc_;

		
};


#endif

