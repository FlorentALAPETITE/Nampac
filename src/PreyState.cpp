#include <PreyState.hpp>
#include <Pacman.hpp>


PreyState::PreyState(Pacman* pacman):PacmanState(pacman){
}

bool PreyState::canEatGhost(){
	return false;
}

void PreyState::decrementRemainingMovement(){}



void PreyState::addRemainingMovement(int m){}


void PreyState::changeStateHunter(){}

void PreyState::changeStatePrey(){	
}


