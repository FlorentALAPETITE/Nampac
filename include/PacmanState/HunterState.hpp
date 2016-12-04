#ifndef DEF_HUNTERSTATE
#define DEF_HUNTERSTATE

#include <SDL2/SDL.h>
#include <PacmanState/PacmanState.hpp>

using namespace std;

/**
 * \brief HunterState concrete pattern implementation for the PacmanState.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Hunter state used for the Pacman.
 *
 */
class HunterState: public PacmanState {

	public:

		/**
		 * HunterState(Pacman* pacman);
		 * \brief HunterState constructor.
		 *		
		 * \param pacman : the pacman to change state.
		 */
		HunterState(Pacman* pacman);

		/**
		 * bool canEatGhost() override;
		 * \brief Method used to know if the pacman can eat ghosts (return true).
		 *		
		 */	
		bool canEatGhost() override;

		/**
		 * void decrementRemainingMovement() override;
		 * \brief Method used to decrement remaining movement.
		 *		
		 */	
		void decrementRemainingMovement() override;

		/**
		 * void addRemainingMovement(int m) override;
		 * \brief Method used to add remaining movement.
		 *		
		 * \param m : the remaining movement to be added.
		 */	
		void addRemainingMovement(int m) override;

		/**
		 * void changeStateHunter() override;
		 * \brief Method used to change the PacmanState to a HunterState. In this state, only add duration to the state.
		 *		
		 */	
		void changeStateHunter() override;

		/**
		 * void changeStatePrey() override;
		 * \brief Method used to change the PacmanState to a PreyState.
		 *		
		 */	
		void changeStatePrey() override;

	protected:
		int remainingMovement_;

};

#endif