#ifndef DEF_PACMANSTATE
#define DEF_PACMANSTATE

#include <SDL2/SDL.h>

using namespace std;	


class Pacman;

/**
 * \brief State pattern implementation for the Pacman.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Abstract class that implements the state pattern. Change dynamically the behaviour of the Pacman.
 *
 */
class PacmanState {

	public:
		/**
		 * PacmanState(Pacman* pacman);
		 * \brief PacmanState constructor.
		 *		
		 * \param pacman : the pacman to change state.
		 */
		PacmanState(Pacman* pacman);

		/**
		 * virtual bool canEatGhost() = 0;
		 * \brief Abstract method canEatGhost : return a bool representing the Pacman ability to eat Ghosts.
		 *		
		 */	
		virtual bool canEatGhost() = 0;

		/**
		 * virtual void decrementRemainingMovement()=0;
		 * \brief Abstract method decrementRemainingMovement of PacmanState.
		 *		
		 */	
		virtual void decrementRemainingMovement()=0;

		/**
		 * virtual void addRemainingMovement(int m)=0;
		 * \brief Abstract method addRemainingMovement of PacmanState.
		 *		
		 * \param m : the remaining movement to be added.
		 */	
		virtual void addRemainingMovement(int m)=0;

		/**
		 * virtual void changeStatePrey()=0;
		 * \brief Abstract method changeStatePrey of PacmanState. Make (or not) the transition from the current state to the PreyState.
		 *		
		 */	
		virtual void changeStatePrey()=0;

		/**
		 * virtual void changeStateHunter()=0;
		 * \brief Abstract method changeStateHunter of PacmanState. Make (or not) the transition from the current state to the HunterState.
		 *		
		 */	
		virtual void changeStateHunter()=0;
		

	protected:
		Pacman* pacman_;		
		

};

#endif