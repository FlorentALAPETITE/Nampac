#include <BlueGhost.hpp>
#include <iostream>


BlueGhost::BlueGhost(int posX, int posY, SDL_Renderer* renderer):Ghost("sprites/blueGhost.bmp",posX,posY,renderer){	
	currentMovementState_ = movementUnpredictableState_;
}