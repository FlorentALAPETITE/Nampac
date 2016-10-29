#ifndef DEF_WALL
#define DEF_WALL

#include <MapElement.hpp>


class Wall : public MapElement{	

	public:		
		Wall(int, int ,SDL_Renderer*);	
	    bool canBeCrossed() override;
	    Bonus* getBonus();
	    
};


#endif