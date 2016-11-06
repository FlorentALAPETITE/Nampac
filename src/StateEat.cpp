#include <Pacman.hpp>
#include <StateEat.hpp>

StateEat::StateEat(Pacman* pacman, int time, int remainingTime):AGumEatState(pacman, time, remainingTime){
}

void StateEat::EatBonus(){}
void StateEat::EndBonus(){}