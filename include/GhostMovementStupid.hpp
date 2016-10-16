#ifndef DEF_GHOSTMOVEMENTSTUPID
#define DEF_GHOSTMOVEMENTSTUPID

#include <GhostMovementState.hpp>

using namespace std;

class GhostMovementStupid : public GhostMovementState {

	public:
		GhostMovementStupid(Ghost *);
		void calculateDirection() override;
		
};


#endif
