#ifndef DEF_GHOSTMOVEMENTSTATE
#define DEF_GHOSTMOVEMENTSTATE

#include <memory>

using namespace std;

class Ghost;

class GameEngine;

/**
 * \brief State pattern implementation for the ghost.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * It is a abstract class to represent state pattern.
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
		 * \brief abstract methode calculateDirection of GhostMovementState.
		 *		
		 */		
		virtual void calculateDirection() = 0;

		/**
		 * void moveCharacter(GameEngine* g, int speed);
		 * \brief methode used to move a character
		 *		
		 * \param g : GameEngine used to move character.
		 * \param speed : the speed used to move character.
		 */
		virtual void moveCharacter(GameEngine* g, int speed);

		/**
		 * void setMovementDeadState();
		 * \brief methode used to change state into dead state.
		 *		
		 */	
		virtual void setMovementDeadState();

		/**
		 * void setMovementAmbushState();
		 * \brief methode used to change state into ambush state.
		 *		
		 */	
		virtual void setMovementAmbushState();

		/**
		 * void setMovementStupidState();
		 * \brief methode used to change state into stupid state.
		 *		
		 */	
		virtual void setMovementStupidState();
		
		/**
		 * void setMovementUnpredictableState();
		 * \brief methode used to change state into unpredictable state.
		 *		
		 */	
		virtual void setMovementUnpredictableState();
		
		/**
		 * void setMovementChaseState();
		 * \brief methode used to change state into chase state.
		 *		
		 */	
		virtual void setMovementChaseState();

		/**
		 * void backToClassicState();
		 * \brief methode used to change state into classic state.
		 *		
		 */	
		void backToClassicState();

		/**
		 * void void setLifeTime(int l);
		 * \brief methode used to set life time to l .
		 *		
		 */	
		void setLifeTime(int l);

	protected:
		Ghost* ghost_;
		int nextDirectionCalc_;
		int stateLifeTime_;

		
};


#endif

