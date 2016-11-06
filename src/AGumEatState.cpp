#include <Pacman.hpp>
#include <AGumEatState.hpp>

AGumEatState::AGumEatState(Pacman* pacman, int time, int remainingTime):pacman_(pacman), time_(time), remainingTime_(remainingTime){

}

int AGumEatState::getTime(){
	return time_;
}
int AGumEatState::getRemainingTime(){
	return remainingTime_;
}