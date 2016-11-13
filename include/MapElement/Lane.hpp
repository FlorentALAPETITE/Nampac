#ifndef DEF_LANE
#define DEF_LANE

#include <MapElement/MapElement.hpp>
#include <Prototype/Prototype.hpp>

using namespace std;

class Lane : public MapElement, public Prototype<Lane>{	

	public:		
		Lane(int , int ,SDL_Renderer*);	
		Lane(const Lane &lane);
	    bool canBeCrossed() override;
	    shared_ptr<Lane> clone(int c, int l) override;

};


#endif