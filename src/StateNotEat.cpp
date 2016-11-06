#include <Pacman.hpp>
#include <StateNotEat.hpp>

StateNotEat::StateNotEat(Pacman* pacman, int time, int remainingTime):AGumEatState(pacman, time, remainingTime){

}

void StateNotEat::EatBonus(){}
void StateNotEat::EndBonus(){}