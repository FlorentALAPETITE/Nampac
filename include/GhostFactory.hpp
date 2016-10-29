#ifndef DEF_GHOSTFACTORY
#define DEF_GHOSTFACTORY

#include <AbstractGhostFactory.hpp>

using namespace std;

class GhostFactory : public AbstractGhostFactory{

	public:
		unique_ptr<Ghost> createGhost(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer) override;


};


#endif