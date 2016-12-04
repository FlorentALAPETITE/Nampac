#ifndef DEF_PACMANSTATE
#define DEF_PACMANSTATE

#include <SDL2/SDL.h>

using namespace std;	


class Pacman;

/**
 * \brief State pattern implementation for the pacman.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * It is a abstract class to represent state pattern.
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
		 * \brief abstract methode canEatGhost of PacmanState.
		 *		
		 */	
		virtual bool canEatGhost() = 0;

		/**
		 * virtual void decrementRemainingMovement()=0;
		 * \brief abstract methode decrementRemainingMovement of PacmanState.
		 *		
		 */	
		virtual void decrementRemainingMovement()=0;

		/**
		 * virtual void addRemainingMovement(int m)=0;
		 * \brief abstract methode addRemainingMovement of PacmanState.
		 *		
		 * \param m : the remaining movement to be added.
		 */	
		virtual void addRemainingMovement(int m)=0;

		/**
		 * virtual void changeStatePrey()=0;
		 * \brief abstract methode changeStatePrey of PacmanState.
		 *		
		 */	
		virtual void changeStatePrey()=0;

		/**
		 * virtual void changeStateHunter()=0;
		 * \brief abstract methode changeStateHunter of PacmanState.
		 *		
		 */	
		virtual void changeStateHunter()=0;
		

	protected:
		Pacman* pacman_;		
		

};

#endif