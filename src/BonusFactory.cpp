#include <Prototype/BonusFactory.hpp>

using namespace std;


BonusFactory::BonusFactory(const int sizeSprite, SDL_Renderer* renderer): sizeSprite_(sizeSprite){
	gumBonusPrototype_ = shared_ptr<Gum> (new Gum(renderer, 0, 0));
	slowGhostBonusPrototype_ = shared_ptr<SlowGhostBonus> (new SlowGhostBonus(renderer, 0, 0));
	speedGhostBonusPrototype_ = shared_ptr<SpeedGhostBonus> (new SpeedGhostBonus(renderer, 0, 0));
	speedPacmanBonusPrototype_ = shared_ptr<SpeedPacmanBonus> (new SpeedPacmanBonus(renderer, 0, 0));
	slowPacmanBonusPrototype_ = shared_ptr<SlowPacmanBonus> (new SlowPacmanBonus(renderer, 0, 0));
	hunterBonusPrototype_ = shared_ptr<HunterBonus> (new HunterBonus(renderer, 0, 0));
	stupidGhostBonusPrototype_ = shared_ptr<StupidGhostBonus> (new StupidGhostBonus(renderer, 0, 0));
}



shared_ptr<Bonus> BonusFactory::createBonus(const char type, const unsigned int c, const unsigned int l, int &gumNumber){
	shared_ptr<Bonus> bonus;

	switch(type){
		case '0':
			bonus = gumBonusPrototype_->clone();
			bonus->setPosition(c*sizeSprite_+8,l*sizeSprite_+8);
			gumNumber++;
			break;

		case '.':
			bonus = nullptr;
			break;

		case '~':
			bonus = slowGhostBonusPrototype_->clone();
			bonus->setPosition(c*sizeSprite_+3,l*sizeSprite_+3);
			break;

		case '#':
			bonus = speedGhostBonusPrototype_->clone();
			bonus->setPosition(c*sizeSprite_+3,l*sizeSprite_+3);
			break;

		case '+':
			bonus = speedPacmanBonusPrototype_->clone();
			bonus->setPosition(c*sizeSprite_+3,l*sizeSprite_+3);
			break;

		case '-':
			bonus = slowPacmanBonusPrototype_->clone();
			bonus->setPosition(c*sizeSprite_+3,l*sizeSprite_+3);
			break;

		case '$':
			bonus = hunterBonusPrototype_->clone();
			bonus->setPosition(c*sizeSprite_+3,l*sizeSprite_+3);
			break;

		case '!':
			bonus = stupidGhostBonusPrototype_->clone();
			bonus->setPosition(c*sizeSprite_+3,l*sizeSprite_+3);
			break;

	}

	return bonus;


}