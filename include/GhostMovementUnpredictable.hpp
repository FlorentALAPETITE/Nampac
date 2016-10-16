#ifndef DEF_GHOSTMOVEMENTUNPREDICTABLE
#define DEF_GHOSTMOVEMENTUNPREDICTABLE

#include <GhostMovementState.hpp>

using namespace std;

class GhostMovementUnpredictable : public GhostMovementState {

	public:
		GhostMovementUnpredictable(Ghost *);
		void calculateDirection() override;
		
};


#endif
