#ifndef DEF_WALL
#define DEF_WALL

#include <MapElement/MapElement.hpp>


class Wall : public MapElement{	

	public:		
		Wall(int, int ,SDL_Renderer*);	
	    bool canBeCrossed() override;	   
};


#endif