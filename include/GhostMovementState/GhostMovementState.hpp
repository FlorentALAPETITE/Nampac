#ifndef DEF_GHOSTMOVEMENTSTATE
#define DEF_GHOSTMOVEMENTSTATE

#include <memory>

using namespace std;

class Ghost;

class GameEngine;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Abstract class that represents a state pattern for the ghosts' A.I.
 *
 */
class GhostMovementState {

	public:

		/**
		 * GhostMovementState(Ghost* g);
		 * \brief GhostMovementState constructor.
		 *		
		 * \param g : the ghost to change state.
		 */
		GhostMovementState(Ghost* g);

		/**
		 * void calculateDirection() = 0;
		 * \brief Abstract method calculateDirection of GhostMovementState.
		 *		
		 */		
		virtual void calculateDirection() = 0;

		/**
		 * void moveCharacter(GameEngine* g, int speed);
		 * \brief Method used to move a character
		 *		
		 * \param g : GameEngine used to move character.
		 * \param speed : the speed used to move character.
		 */
		virtual void moveCharacter(GameEngine* g, int speed);

		/**
		 * void setMovementDeadState();
		 * \brief Method used to change state into dead state.
		 *		
		 */	
		virtual void setMovementDeadState();

		/**
		 * void setMovementAmbushState();
		 * \brief Method used to change state into ambush state.
		 *		
		 */	
		virtual void setMovementAmbushState();

		/**
		 * void setMovementStupidState();
		 * \brief Method used to change state into stupid state.
		 *		
		 */	
		virtual void setMovementStupidState();
		
		/**
		 * void setMovementUnpredictableState();
		 * \brief Method used to change state into unpredictable state.
		 *		
		 */	
		virtual void setMovementUnpredictableState();
		
		/**
		 * void setMovementChaseState();
		 * \brief Method used to change state into chase state.
		 *		
		 */	
		virtual void setMovementChaseState();

		/**
		 * void backToClassicState();
		 * \brief Method used to change the ghost state to the classic state of the ghost.
		 *		
		 */	
		void backToClassicState();

		/**
		 * void void setLifeTime(int l);
		 * \brief Method used to set life time to l .
		 *		
		 */	
		void setLifeTime(int l);

	protected:
		Ghost* ghost_;
		int nextDirectionCalc_;
		int stateLifeTime_;

		
};


#endif

