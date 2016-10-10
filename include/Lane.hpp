#ifndef DEF_LANE
#define DEF_LANE

#include <MapElement.hpp>

class Lane : public MapElement{	

	public:		
		Lane(char*, int , int ,SDL_Renderer*);	
	    bool canBeCrossed() override;

};


#endif