#include <PacmanState/HunterState.hpp>
#include <Character/Pacman.hpp>


HunterState::HunterState(Pacman* pacman):PacmanState(pacman), remainingMovement_(200){
}

bool HunterState::canEatGhost(){
	return true;
}

void HunterState::decrementRemainingMovement(){
	--remainingMovement_;
	if(remainingMovement_==0)
		changeStatePrey();
}


void HunterState::addRemainingMovement(int m){
	remainingMovement_+=m;
}

void HunterState::changeStateHunter(){
	addRemainingMovement(200);
}

void HunterState::changeStatePrey(){
	addRemainingMovement(200);
	pacman_->changeStatePrey();
}


