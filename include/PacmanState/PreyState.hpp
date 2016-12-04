#ifndef DEF_PREYSTATE
#define DEF_PREYSTATE

#include <SDL2/SDL.h>
#include <PacmanState/PacmanState.hpp>

using namespace std;

/**
 * \brief PreyState pattern implementation for the pacmanState.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * It is prey state used for pacman.
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
		 * \brief methode used to know if the pacman can eat ghosts (return false).
		 *		
		 */	
		bool canEatGhost() override;
		
		/**
		 * void decrementRemainingMovement() override;
		 * \brief methode used to decrement remaining movement.
		 *		
		 */	
		void decrementRemainingMovement() override;
		
		/**
		 * void addRemainingMovement(int m) override;
		 * \brief methode used to add remaining movement.
		 *		
		 * \param m : the remaining movement to be added.
		 */	
		void addRemainingMovement(int m) override;
		
		/**
		 * void changeStateHunter() override;
		 * \brief methode used to change pacman state into hunter state.
		 *		
		 */	
		void changeStateHunter() override;
		
		/**
		 * void changeStatePrey() override;
		 * \brief methode used to change pacman state into prey state.
		 *		
		 */	
		void changeStatePrey() override;


};

#endif