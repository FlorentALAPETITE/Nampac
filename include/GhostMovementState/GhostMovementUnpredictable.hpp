#ifndef DEF_GHOSTMOVEMENTUNPREDICTABLE
#define DEF_GHOSTMOVEMENTUNPREDICTABLE

#include <GhostMovementState/GhostMovementState.hpp>

using namespace std;

/**
 * \brief State pattern implementation for the ghost movement.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * It is stupid state used for ghosts.
 *
 */
class GhostMovementUnpredictable : public GhostMovementState {

	public:
		/**
		 * GhostMovementUnpredictable(Ghost* g);
		 * \brief GhostMovementUnpredictable constructor.
		 *		
		 * \param g : the ghost to change state.
		 */
		GhostMovementUnpredictable(Ghost* g);

		/**
		 * void calculateDirection() override;
		 * \brief override calculateDirection of GhostMovementState. This methode change direction in a way "unpredictable".
		 *		
		 */
		void calculateDirection() override;
		
};


#endif
