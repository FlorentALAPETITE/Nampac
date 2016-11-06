#ifndef DEF_CHARACTERDECORATOR
#define DEF_CHARACTERDECORATOR

#include <memory>
#include <Character.hpp>

using namespace std;

class CharacterDecorator : public Character{

	protected:
		shared_ptr<Character> character_;		

	public:
		CharacterDecorator(shared_ptr<Character>);
		virtual int getSpeed() override =0;		
		void changePosition(int,int) override;
		int getPosX() override;
		int getPosY() override;
		vector<SDL_Texture*> getCharacterTexture() override;
		SDL_Rect* getTextureRect() override;
		int getDirection() override;
		void setDirection(int) override;		
		void moveCharacter(GameEngine*,int) override;
		void calculateNextDirection() override;
		void changeStateHunter() override;
		
};


#endif