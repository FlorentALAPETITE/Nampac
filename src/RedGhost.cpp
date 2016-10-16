#include <RedGhost.hpp>
#include <iostream>


RedGhost::RedGhost(int posX, int posY, SDL_Renderer* renderer):Ghost("sprites/redGhost.bmp",posX,posY,renderer){	
	currentMovementState_ = movementChaseState_;
}