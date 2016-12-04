#ifndef DEF_GHOSTMOVEMENTCHASE
#define DEF_GHOSTMOVEMENTCHASE

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Chase state used for the ghosts.
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
		 * \brief Override calculateDirection of GhostMovementState. This method change direction in a "chase" way.
		 *		
		 */
		void calculateDirection() override;
		
};


#endif
