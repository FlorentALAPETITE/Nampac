#ifndef DEF_GHOSTMOVEMENTAMBUSH
#define DEF_GHOSTMOVEMENTAMBUSH

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Ambush state used for the ghosts.
 *
 */


class GhostMovementAmbush : public GhostMovementState {

	public:
		/**
		 * GhostMovementAmbush(Ghost* g);
		 * \brief GhostMovementAmbush constructor.
		 *		
		 * \param g : the ghost to change state.
		 */
		GhostMovementAmbush(Ghost* g);

		/**
		 * void calculateDirection() override;
		 * \brief Override calculateDirection of GhostMovementState. This method change direction in an "ambush" way.
		 *		
		 */
		void calculateDirection() override;
		
};


#endif
