#include <PacmanState/PreyState.hpp>
#include <Character/Pacman.hpp>


PreyState::PreyState(Pacman* pacman):PacmanState(pacman){
}

bool PreyState::canEatGhost(){
	return false;
}

void PreyState::decrementRemainingMovement(){}



void PreyState::addRemainingMovement(int m){}


void PreyState::changeStateHunter(){
	pacman_->changeStateHunter();
}

void PreyState::changeStatePrey(){}


