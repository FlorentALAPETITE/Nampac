#ifndef DEF_WALL
#define DEF_WALL

#include <MapElement.hpp>


class Wall : public MapElement{	

	public:		
		Wall(char*, int , int ,SDL_Renderer*);	
	    bool canBeCrossed() override;

};


#endif