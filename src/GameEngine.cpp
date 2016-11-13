#include <GameEngine.hpp>
#include <string.h>
#include <memory>
#include <MapReader.hpp>
#include <math.h>
#include <stdlib.h>   
#include <ctype.h>
#include <CharacterDecorator/SpeededCharacter.hpp>
#include <CharacterDecorator/SlowedCharacter.hpp>
#include <Character/Pacman.hpp>



using namespace std;


GameEngine::GameEngine():gameOver_(false),randNumber_(0),playerScore_(0),gumNumber_(0){
	    
                  
    // SDL initialization 
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw string(SDL_GetError());       
    }
        
   
    //Window initialization
    window_ = SDL_CreateWindow("Nampac", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 775, SDL_WINDOW_SHOWN);

    if(window_ == 0)
    {
        throw string(SDL_GetError());        
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);     


    ghosts_ = vector<shared_ptr<Character>>();
    

    TTF_Init();

    fontScoring_ = TTF_OpenFont("./font/Xolonium-Regular.ttf", 30);
    fontEndGame_ = TTF_OpenFont("./font/Xolonium-Regular.ttf", 250);
    red_ = {255, 0, 0};  
	white_ = {255, 255, 255};  
	green_ = {0,255,0};

	playerScoreRect_ = {540,685,80,40};

	mapElementFactory_ = unique_ptr<MapElementFactory>(new MapElementFactory(sizeSprite,renderer_));
	ghostFactory_ = unique_ptr<GhostFactory>(new GhostFactory(sizeSprite,renderer_));
        
}



GameEngine::~GameEngine(){		

	SDL_DestroyRenderer(renderer_); 	

	if(endGameTexture_!=nullptr)
		SDL_DestroyTexture(endGameTexture_);

	if(endGameSurface_!=nullptr)
		SDL_FreeSurface(endGameSurface_);

	if(playerScoreTexture_!=nullptr)
		SDL_DestroyTexture(playerScoreTexture_);

	if(playerScoreSurface_!=nullptr)
		SDL_FreeSurface(playerScoreSurface_);

    SDL_DestroyWindow(window_);

}


void GameEngine::renderCharacter(shared_ptr<Character> c){
	for(auto texture : c->getCharacterTexture())    
 		SDL_RenderCopy(renderer_,texture,NULL,c->getTextureRect()); //Render the sprite for the character			

}



void GameEngine::renderCharacters(){
	renderCharacter(pacman_);
	for(unsigned int i=0;i<ghosts_.size();++i){
		renderCharacter(ghosts_.at(i));
	}
}



void GameEngine::moveCharacter(shared_ptr<Character> c){
	c->moveCharacter(this, c->getSpeed());	
		
}


void GameEngine::checkAllCharactersColision(){	
	for(unsigned int i=0;i<ghosts_.size();++i){
		if (checkColisionSDLRect(ghosts_.at(i)->getTextureRect(), pacman_->getTextureRect())){
			if(!pacman_->canEatGhost())
				gameOver_ = true;
			else{				
				ghosts_.at(i)->setDeathPosition();	
				ghosts_.at(i)->askChangeMovementDeadState();			
			}
		}
	}
}


void GameEngine::moveCharacters(){
	moveCharacter(pacman_);		

	for(unsigned int i=0;i<ghosts_.size();++i){
		srand(randNumber_);
		randNumber_+=100;
		ghosts_.at(i)->calculateNextDirection();
		moveCharacter(ghosts_.at(i));
	}
	
}


void GameEngine::handleBonus(char type){

	switch(type){

		case '0': //Bonus : gum
			--gumNumber_;
			break;

		case '~':  //Bonus : slow ghost
			for(unsigned int i=0;i<ghosts_.size();++i)
				ghosts_[i]=shared_ptr<Character>(new SlowedCharacter(ghosts_[i]));			
			break;

		case '#':  //Bonus : speed ghost
			for(unsigned int i=0;i<ghosts_.size();++i)
				ghosts_[i]=shared_ptr<Character>(new SpeededCharacter(ghosts_[i]));			
			break;

		case '+':  //Bonus : speed pacman
			pacman_=shared_ptr<Character>(new SpeededCharacter(pacman_));			
			break;

		case '-':  //Bonus : slow pacman
			pacman_=shared_ptr<Character>(new SlowedCharacter(pacman_));			
			break;

		case '$':  //Bonus : hunter pacman
			pacman_->askChangeStateHunter();			
			break;

		case '!':  //Bonus : stupid ghost
			for(unsigned int i=0;i<ghosts_.size();++i)
				ghosts_[i]->askChangeMovementStupidState();		
			break;
	}

}



void GameEngine::changePacmanDirection(int direction){
	if(pacman_->getPosX()>=25 && pacman_->getPosX()<=675 && pacman_->getPosY()>=25 && pacman_->getPosY()<=745 )
		pacman_->setDirection(direction);
}



void GameEngine::createMap(vector<vector<char>> const& laby){		

	mapElements_ = vector<vector<shared_ptr<MapElement>>> ();

	char charMapElement;

	for (unsigned int l = 0; l < laby.size(); ++l)
	{
		mapElements_.push_back(vector<shared_ptr<MapElement>>());
		for (unsigned int c = 0; c < laby[0].size(); ++c)
		{
			charMapElement = laby[l][c];

			if(charMapElement == 'p'){  // Construct a Pacman
				pacman_ = shared_ptr<Pacman>(new Pacman((char*)"sprites/Pacman/pacmanClose.bmp",5,c*sizeSprite,l*sizeSprite,renderer_)); 							
				charMapElement = '0';
			}

			else if(isalpha(charMapElement)){  // Request ghost construction -> ghostFactory
				ghosts_.push_back(ghostFactory_->createGhost(charMapElement,c,l));
				charMapElement = '0';
			}

			// Request MapElement construction -> mapElementFactory
			mapElements_[l].push_back(mapElementFactory_->createMapElement(charMapElement,c,l,gumNumber_));			
		}
	}
	
	if (pacman_==nullptr)	
		throw string("Erreur : veuillez disposer un pacman (p) dans la map du jeu.");
}



void GameEngine::renderMap(){
	shared_ptr<Bonus> bonus;
	for (unsigned int l = 0; l < mapElements_.size(); ++l){
		for (unsigned int c = 0; c < mapElements_[0].size(); ++c){
			SDL_RenderCopy(renderer_, mapElements_.at(l).at(c)->getMapElementTexture(), NULL, mapElements_.at(l).at(c)->getTextureRect());
			bonus = mapElements_.at(l).at(c)->getBonus();
			if(bonus!=nullptr){				
				SDL_RenderCopy(renderer_, bonus->getTexture(), NULL, bonus->getTextureRect());
			}
		}
	}
}


void GameEngine::clearRenderer(){
	SDL_RenderClear(renderer_);
}


void GameEngine::renderPresent(){
	SDL_RenderPresent(renderer_);
}


int GameEngine::getSizeSprite(){ return sizeSprite; }


shared_ptr<MapElement> GameEngine::getMapElement(int x, int y){		
	return mapElements_[y][x];
}


bool GameEngine::checkColision(int x, int y){
	int x1 = x/sizeSprite;
   	int y1 = y/sizeSprite;
   	int x2 = (x + sizeSprite -1 ) /sizeSprite;  
   	int y2 = (y + sizeSprite -1 ) /sizeSprite;
   	for(int i = x1; i <=x2; ++i)
   	{
    	for(int j = y1; j<=y2; ++j)
    	{
        	if (!getMapElement(i,j)->canBeCrossed())
            	return true;
    	}
  	}
	return false;
}


bool GameEngine::checkColisionSDLRect(SDL_Rect* r1, SDL_Rect* r2){
	if(
		(r2->x >= r1->x + r1->w) || // too right
		(r2->x + r2->w <= r1->x) || // too left
		(r2->y >= r1->y + r1->h) || // too down
		(r2->y + r2->h <= r1->y) // too top
		){
		return false;
	}
	return true;

}



void GameEngine::renderEndGameMessage(const char* message, SDL_Color color){
	
	endGameSurface_ = TTF_RenderText_Solid(fontEndGame_, message, color); 

	endGameTexture_ = SDL_CreateTextureFromSurface(renderer_, endGameSurface_); 

	endGameRect_ = {150,250,400,200};

	SDL_RenderCopy(renderer_, endGameTexture_, NULL, &endGameRect_); 
}





void GameEngine::renderPlayerScore(){	

	const char* score = (string("Score : ")+to_string(playerScore_)).c_str();

	playerScoreSurface_ = TTF_RenderText_Solid(fontScoring_, score, white_); 

	playerScoreTexture_ = SDL_CreateTextureFromSurface(renderer_, playerScoreSurface_); 	
	
	SDL_RenderCopy(renderer_, playerScoreTexture_, NULL, &playerScoreRect_); 
	
}


void GameEngine::checkBonusEating(){
	shared_ptr<Bonus> actualBonus = getMapElement(pacman_->getPosX()/sizeSprite, pacman_->getPosY()/sizeSprite)->getBonus(); // Try to get the bonus on the case in which the Pacman is.
	if(actualBonus != nullptr){  // If there's a bonus
		if(checkColisionSDLRect(pacman_->getTextureRect(), actualBonus->getTextureRect())){
			playerScore_+=actualBonus->getPoint();
			handleBonus(actualBonus->getBonusType());
			getMapElement(pacman_->getPosX()/sizeSprite, pacman_->getPosY()/sizeSprite)->eatBonus();
		}
	}
}


void GameEngine::checkVictory(){
	victory_= (gumNumber_==0);
}



void GameEngine::launchNampac(const char* mapLocation){
	 
        SDL_Event events;
        bool quit(false);
        
        vector<vector<char>> laby = MapReader::BuildMap(mapLocation);

        createMap(laby); 

        renderMap(); 
        renderCharacters();
        renderPlayerScore();
        renderPresent();

        // While window isn't close
        while(!quit){  

        	//Handle quit event
        	while (SDL_PollEvent(&events)) {

                if(events.window.event == SDL_WINDOWEVENT_CLOSE)
                    quit = true;

                // arrow key events
                switch( events.key.keysym.sym ){ 
                    case SDLK_UP: // keyboard key up
                        changePacmanDirection(2);
                        break;
                    case SDLK_DOWN:  // keyboard key down
                        changePacmanDirection(3);
                        break;
                    case SDLK_RIGHT:  // keyboard key right 
                        changePacmanDirection(0);
                        break;
                    case SDLK_LEFT:  // keyboard key left
                        changePacmanDirection(1);
                        break;

                  }           
            }


        	if(!gameOver_ && !victory_){            
        		// Game routine :
	            moveCharacters(); // move all the characters
	            clearRenderer();  // clear the screen
	            renderMap();  // render the map
	            renderCharacters();  // render characters
	            renderPlayerScore();  // render the player score actualized
	            renderPresent();   // show the screen
	            checkAllCharactersColision(); // check if pacman is in a ghost
	            checkVictory();

	            SDL_Delay(25);

	            if(playerScore_!=0)
	            	--playerScore_;

	            if(gameOver_){
	            	renderEndGameMessage("GAME OVER", red_);  // render the game over message
	            	renderPresent();
	            	
	            }

	            if (victory_){
	            	renderEndGameMessage("VICTORY", green_);  // render the victory message
	            	renderPresent();
	            }



	        }

            

        }   

  }