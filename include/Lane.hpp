#ifndef DEF_LANE
#define DEF_LANE

#include <Bonus.hpp>
#include <MapElement.hpp>

class Lane : public MapElement{	

	public:		
		Lane(int , int ,SDL_Renderer*);	
	    bool canBeCrossed() override;
	    Bonus* getBonus() override;

	private:
		Bonus* bonus_;
};


#endif