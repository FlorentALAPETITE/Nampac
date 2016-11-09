#ifndef DEF_GHOSTMOVEMENTAMBUSH
#define DEF_GHOSTMOVEMENTAMBUSH

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

class GhostMovementAmbush : public GhostMovementState {

	public:
		GhostMovementAmbush(Ghost *);
		void calculateDirection() override;
		
};


#endif
