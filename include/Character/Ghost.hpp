#ifndef DEF_GHOST
#define DEF_GHOST

#include <Character/Character.hpp>
#include <GhostMovementState/GhostMovementState.hpp>
#include <memory>


using namespace std;



class Ghost : public Character{

	public:
		Ghost(char*, int, int, SDL_Renderer*,int,int);
		Ghost(const Ghost &ghost);

		void calculateNextDirection() override;
		void moveCharacter(GameEngine*,int) override;
		void setDeathPosition() override;
		void setMovementDeadState() override;
		void setMovementAmbushState() override;
		void setMovementStupidState() override;
		void setMovementUnpredictableState() override;
		void setMovementChaseState() override;
		virtual void backToClassicState()=0;
		void askChangeMovementDeadState() override;
		void askChangeMovementAmbushState() override;
		void askChangeMovementStupidState() override;
		void askChangeMovementUnpredictableState() override;
		void askChangeMovementChaseState() override;		

	protected:
		shared_ptr<GhostMovementState> currentMovementState_;

		shared_ptr<GhostMovementState> movementChaseState_;		
		shared_ptr<GhostMovementState> movementAmbushState_;
		shared_ptr<GhostMovementState> movementStupidState_;
		shared_ptr<GhostMovementState> movementUnpredictableState_;
		shared_ptr<GhostMovementState> movementDeadState_;	

		int deathPosX_;
		int deathPosY_;	

};


#endif

