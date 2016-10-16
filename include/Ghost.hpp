#ifndef DEF_GHOST
#define DEF_GHOST


#include <Character.hpp>
#include <GhostMovementState.hpp>
#include <GhostMovementChase.hpp>
#include <GhostMovementAmbush.hpp>
#include <GhostMovementStupid.hpp>
#include <GhostMovementUnpredictable.hpp>
#include <memory>

using namespace std;



class Ghost : public Character{

	public:
		Ghost(char*, int, int, SDL_Renderer*);
		void calculateNextDirection();

	protected:
		shared_ptr<GhostMovementState> currentMovementState_;

		shared_ptr<GhostMovementChase> movementChaseState_;		
		shared_ptr<GhostMovementAmbush> movementAmbushState_;
		shared_ptr<GhostMovementStupid> movementStupidState_;
		shared_ptr<GhostMovementUnpredictable> movementUnpredictableState_;		

};


#endif

