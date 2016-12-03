#ifndef DEF_GHOSTMOVEMENTAMBUSH
#define DEF_GHOSTMOVEMENTAMBUSH

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * It is ambush state used for ghosts.
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
		 * \brief override calculateDirection of GhostMovementState. This methode change direction in a way "ambush".
		 *		
		 */
		void calculateDirection() override;
		
};


#endif
