#ifndef DEF_GHOSTMOVEMENTSTUPID
#define DEF_GHOSTMOVEMENTSTUPID

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Stupid state used for ghosts.
 *
 */
class GhostMovementStupid : public GhostMovementState {

	public:

		/**
		 * GhostMovementStupid(Ghost* g);
		 * \brief GhostMovementStupid constructor.
		 *		
		 * \param g : the ghost to change state.
		 */
		GhostMovementStupid(Ghost* g);

		/**
		 * void calculateDirection() override;
		 * \brief Override calculateDirection of GhostMovementState. This method change direction in a "stupid" way .
		 *		
		 */
		void calculateDirection() override;
		
};


#endif
