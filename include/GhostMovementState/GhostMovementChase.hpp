#ifndef DEF_GHOSTMOVEMENTCHASE
#define DEF_GHOSTMOVEMENTCHASE

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * It is chase state used for ghosts.
 *
 */

class GhostMovementChase : public GhostMovementState {

	public:
		/**
		 * GhostMovementChase(Ghost* g);
		 * \brief GhostMovementChase constructor.
		 *		
		 * \param g : the ghost to change state.
		 */
		GhostMovementChase(Ghost* g);

		/**
		 * void calculateDirection() override;
		 * \brief override calculateDirection of GhostMovementState. This methode change direction in a way "chase".
		 *		
		 */
		void calculateDirection() override;
		
};


#endif
