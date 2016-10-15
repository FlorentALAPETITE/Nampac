#ifndef DEF_GHOSTMOVEMENTSTATE
#define DEF_GHOSTMOVEMENTSTATE

//#include <Ghost.hpp>
#include <memory>

using namespace std;

class Ghost;

class GhostMovementState {

	public:
		GhostMovementState(Ghost*);
		virtual void calculateDirection() = 0;

	protected:
		Ghost* ghost_;

		
};


#endif

