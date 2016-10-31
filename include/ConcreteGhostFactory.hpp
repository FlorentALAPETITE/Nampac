#ifndef DEF_CONCRETEGHOSTFACTORY
#define DEF_CONCRETEGHOSTFACTORY

#include <GhostFactory.hpp>

using namespace std;

class ConcreteGhostFactory : public GhostFactory{

	public:
		shared_ptr<Character> createGhost(const char type, const unsigned int c, const unsigned int l, const int sizeSprite, SDL_Renderer* renderer) override;


};


#endif