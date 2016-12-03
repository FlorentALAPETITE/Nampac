#ifndef DEF_GHOSTMOVEMENTDEAD
#define DEF_GHOSTMOVEMENTDEAD

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * It is ambush state used for ghosts.
 *
 */

class GhostMovementDead : public GhostMovementState {

	public:
		/**
		 * GhostMovementDead(Ghost* g);
		 * \brief GhostMovementDead constructor.
		 *		
		 * \param g : the ghost to change state.
		 */
		GhostMovementDead(Ghost* g);

		/**
		 * void calculateDirection() override;
		 * \brief override calculateDirection of GhostMovementState. This methode change direction in a way "dead".
		 *		
		 */
		void calculateDirection() override;

		/**
		 * void moveCharacter(GameEngine* g, int speed) override;
		 * \brief methode used to move a character.
		 *		
		 * \param g : GameEngine used to move character.
		 * \param speed : the speed used to move character.
		 */
		void moveCharacter(GameEngine* g, int speed) override;

		/**
		 *void setMovementDeadState() override;
		 * \brief used to change state (Dead).
		 */
		void setMovementDeadState() override;

		/**
		 *void setMovementAmbushState() override;
		 * \brief used to change state (Ambush).
		 */		
		void setMovementAmbushState() override;

		/**
		 *void setMovementStupidState() override;
		 * \brief used to change state (Stupid).
		 */
		void setMovementStupidState() override;

		/**
		 *void setMovementUnpredictableState() override;
		 * \brief used to change state (Unpredictable).
		 */
		void setMovementUnpredictableState() override;

		/**
		 *void setMovementChaseState() override;
		 * \brief used to change state (Chase).
		 */
		void setMovementChaseState() override;


		
};


#endif
