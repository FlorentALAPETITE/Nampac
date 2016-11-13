#ifndef DEF_WALL
#define DEF_WALL

#include <MapElement/MapElement.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class Wall : public MapElement, public Prototype<Wall>{	

	public:		
		Wall(int, int ,SDL_Renderer*);
		Wall(const Wall &wall);	
	    bool canBeCrossed() override;
	    shared_ptr<Wall> clone(int c, int l) override;	   
};


#endif