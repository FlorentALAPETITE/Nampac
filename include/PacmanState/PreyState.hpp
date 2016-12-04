#ifndef DEF_PREYSTATE
#define DEF_PREYSTATE

#include <SDL2/SDL.h>
#include <PacmanState/PacmanState.hpp>

using namespace std;

/**
 * \brief PreyState concrete pattern implementation for the PacmanState.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Prey state used for the Pacman.
 *
 */
class PreyState: public PacmanState {

	public:

		/**
		 * PreyState(Pacman* pacman);
		 * \brief PreyState constructor.
		 *		
		 * \param pacman : the pacman to change state.
		 */
		PreyState(Pacman* pacman);		
		
		/**
		 * bool canEatGhost() override;
		 * \brief Method used to know if the pacman can eat ghosts (return false).
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
		 * \brief Method used to change the PacmanState to a HunterState. 
		 *		
		 */	
		void changeStateHunter() override;
		
		/**
		 * void changeStatePrey() override;
		 * \brief Method used to change the PacmanState to a PreyState. In this state, does nothing (already prey).
		 *		
		 */	
		void changeStatePrey() override;


};

#endif