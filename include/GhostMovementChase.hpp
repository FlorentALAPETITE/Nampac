#ifndef DEF_GHOSTMOVEMENTCHASE
#define DEF_GHOSTMOVEMENTCHASE

#include <GhostMovementState.hpp>

using namespace std;

class GhostMovementChase : public GhostMovementState {

	public:
		GhostMovementChase(Ghost *);
		void calculateDirection() override;
		
};


#endif
