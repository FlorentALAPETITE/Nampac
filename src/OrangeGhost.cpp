#include <OrangeGhost.hpp>
#include <iostream>


OrangeGhost::OrangeGhost(int posX, int posY, SDL_Renderer* renderer):Ghost("sprites/orangeGhost.bmp",posX,posY,renderer){	
	currentMovementState_ = movementStupidState_;
}