#include <Prototype/GhostFactory.hpp>

using namespace std;


GhostFactory::GhostFactory(const int sizeSprite, SDL_Renderer* renderer): sizeSprite_(sizeSprite){
	blueGhostPrototype_ = shared_ptr<BlueGhost>(new BlueGhost(0,0,renderer));
	orangeGhostPrototype_ = shared_ptr<OrangeGhost>(new OrangeGhost(0,0,renderer));
	redGhostPrototype_ = shared_ptr<RedGhost>(new RedGhost(0,0,renderer));
	pinkGhostPrototype_ = shared_ptr<PinkGhost>(new PinkGhost(0,0,renderer));
}

shared_ptr<Ghost> GhostFactory::createGhost(const char type, const unsigned int c, const unsigned int l){
	shared_ptr<Ghost> ghost;

	switch(type){
		case 'R':
			ghost = redGhostPrototype_->clone();			
			break;

		case 'O':
			ghost = orangeGhostPrototype_->clone();
			break;

		case 'B':
			ghost = blueGhostPrototype_->clone();
			break;

		case 'P':
			ghost = pinkGhostPrototype_->clone();
			break;
		
	}
	if(ghost!=nullptr)
		ghost->changePosition(c*sizeSprite_,l*sizeSprite_);

	return ghost;


}