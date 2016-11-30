#ifndef DEF_GHOST
#define DEF_GHOST

#include <Character/Character.hpp>
#include <GhostMovementState/GhostMovementState.hpp>
#include <memory>


using namespace std;


/**
 * \brief Abstract Ghost implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Pacman ennemy : Ghost. Composed with a state pattern (GhostMovementState).
 *
 */

class Ghost : public Character{

	public:
		/**
		 * Ghost(int posX, int posY, SDL_Renderer* renderer);
		 * \brief Abstract Ghost constructor.
		 *
		 * \param sl : path for the ghost sprite location.
		 * \param posX : X position in the 700x775 map. 
		 * \param posY : Y position in the 700x775 map.
		 * \param renderer : unique SDL_Renderer used to render the game.
		 * \param deathPosX : X position for the ghost corpse when killed by Pacman.
		 * \param deathPosY : Y position for the ghost corpse when killed by Pacman.
		 */
		Ghost(char* sl, int posX, int posY, SDL_Renderer* renderer,int deathPosX,int deathPosY);

		/**
		 * Ghost(const Ghost &ghost);
		 * \brief Abstract Ghost copy constructor.
		 * \param ghost : ghost to copy;
		*/
		Ghost(const Ghost &ghost);

		/**
		 * void calculateNextDirection() override;
		 * \brief Ask the current ghost state to calculate the next direction the ghost will take on the map.
		 */
		void calculateNextDirection() override;

		/**
		 * void moveCharacter(GameEngine* g,int speed) override;
		 * \brief Ask the current ghost state to calculate the next direction the ghost will take on the map.

		 * \param g : the GameEngine.
		 * \param speed : the speed of the ghost (needed because of the decoration possibility).
		 */
		void moveCharacter(GameEngine* g,int speed) override;

		/**
		 * void setDeathPosition() override;
		 * \brief Set the current ghost position to his death position.		
		 */
		void setDeathPosition() override;

		/**
		 * void setMovementDeadState() override;
		 * \brief GhostMovementState setter : set the current state to a GhostMovementDead.		
		 */
		void setMovementDeadState() override;

		/**
		 * void setMovementAmbushState() override;
		 * \brief GhostMovementState setter : set the current state to a GhostMovementAmbush.		
		 */
		void setMovementAmbushState() override;

		/**
		 * void setMovementStupidState() override;
		 * \brief GhostMovementState setter : set the current state to a GhostMovementStupid.		
		 */
		void setMovementStupidState() override;

		/**
		 * 	void setMovementUnpredictableState() override;
		 * \brief GhostMovementState setter : set the current state to a GhostMovementUnpredictable.		
		 */
		void setMovementUnpredictableState() override;

		/**
		 * 	void setMovementChaseState() override;
		 * \brief GhostMovementState setter : set the current state to a GhostMovementChase.		
		 */
		void setMovementChaseState() override;

		/**
		 * 	virtual void backToClassicState()=0;
		 * \brief Change the current ghost state to his classic state (different for each ghost type).		
		 */
		virtual void backToClassicState()=0;

		/**
		 * 	void askChangeMovementDeadState() override;
		 * \brief Ask to the ghost current state if a transition can be made to a GhostMovementDead.		
		 */
		void askChangeMovementDeadState() override;

		/**
		 * 	void askChangeMovementAmbushState() override;
		 * \brief Ask to the ghost current state if a transition can be made to a GhostMovementAmbush.		
		 */
		void askChangeMovementAmbushState() override;

		/**
		 * 	void askChangeMovementStupidState() override;
		 * \brief Ask to the ghost current state if a transition can be made to a GhostMovementStupid.		
		 */
		void askChangeMovementStupidState() override;

		/**
		 * 	void askChangeMovementUnpredictableState() override;
		 * \brief Ask to the ghost current state if a transition can be made to a GhostMovementUnpredictable.		
		 */
		void askChangeMovementUnpredictableState() override;

		/**
		 * 	void askChangeMovementChaseState() override;	
		 * \brief Ask to the ghost current state if a transition can be made to a GhostMovementChase.		
		 */
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

		char* spriteLocation_;

};


#endif

