#ifndef DEF_LANE
#define DEF_LANE

#include <MapElement.hpp>

class Lane : public MapElement{	

	public:		
		Lane(int , int ,SDL_Renderer*, Bonus*);	
	    bool canBeCrossed() override;
	    Bonus* getBonus();

};


#endif