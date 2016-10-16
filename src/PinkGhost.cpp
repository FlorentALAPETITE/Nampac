#include <PinkGhost.hpp>
#include <iostream>


PinkGhost::PinkGhost(int posX, int posY, SDL_Renderer* renderer):Ghost("sprites/pinkGhost.bmp",posX,posY,renderer){	
	currentMovementState_ = movementAmbushState_;
}