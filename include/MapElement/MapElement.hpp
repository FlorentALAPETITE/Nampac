#ifndef DEF_MAPELEMENT
#define DEF_MAPELEMENT

#include <SDL2/SDL.h>
#include <Bonus/Bonus.hpp>
#include <memory>

using namespace std;

class MapElement{
	protected:
		SDL_Texture* mapElementTexture_;
		SDL_Surface* mapElementSurface_;
		SDL_Rect textureRect_;
		SDL_Renderer* renderer_;			
		shared_ptr<Bonus> bonus_;
		char* spriteLocation_;

	public:
		MapElement(char*,int,int,SDL_Renderer*);
		MapElement(const MapElement &mapElement);
		~MapElement();
		SDL_Rect* getTextureRect();	
		SDL_Texture* getMapElementTexture();
		virtual bool canBeCrossed()=0;		
		shared_ptr<Bonus> getBonus();
		void eatBonus();
		void setBonus(shared_ptr<Bonus> b);
		void setPosition(int newPosX, int newPosY);

};


#endif