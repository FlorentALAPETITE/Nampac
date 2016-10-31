#include <GameEngine.hpp>
#include <string.h>
#include <memory>
#include <MapReader.hpp>
#include <math.h>
#include <stdlib.h>    
#include <MapElementFactory.hpp>
#include <ctype.h>
#include <SpeededCharacter.hpp>
#include <Pacman.hpp>


using namespace std;


GameEngine::GameEngine():gameOver_(false),randNumber_(0),playerScore_(0){
	    
           
       
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
    fontGameOver_ = TTF_OpenFont("./font/Xolonium-Regular.ttf", 250);
    red_ = {255, 0, 0};  
	white_ = {255, 255, 255};  

	playerScoreRect_ = {540,685,80,40};

	mapElementFactory_ = unique_ptr<MapElementFactory>(new MapElementFactory());
	ghostFactory_ = unique_ptr<GhostFactory>(new GhostFactory());
        
}




void GameEngine::renderCharacter(Character* c){
		    
 	SDL_RenderCopy(renderer_,c->getCharacterTexture(),NULL,c->getTextureRect()); // Copie du sprite grâce au SDL_Renderer	 
			

}



void GameEngine::renderCharacters(){
	renderCharacter(pacman_.get());

	for(unsigned int i=0;i<ghosts_.size();++i){
		renderCharacter(ghosts_.at(i).get());
	}
}



void GameEngine::moveCharacter(Character * c){
	c->moveCharacter(this, c->getSpeed());
	
		
}

void GameEngine::checkAllCharactersColision(){	
	for(unsigned int i=0;i<ghosts_.size();++i){
		if (checkColisionSDLRect(ghosts_.at(i)->getTextureRect(), pacman_->getTextureRect())){
			gameOver_ = true;
		}
	}
}

void GameEngine::moveCharacters(){
	moveCharacter(pacman_.get());
	checkBonusEating();

	for(unsigned int i=0;i<ghosts_.size();++i){
		srand(randNumber_);
		randNumber_+=100;
		ghosts_.at(i)->calculateNextDirection();
		moveCharacter(ghosts_.at(i).get());
	}
	
}

void GameEngine::changePacmanDirection(int direction){
	// int modifiedSpeed = pacman_->getSpeed();
	// bool modified=false;
	// while(modified==false && modifiedSpeed!=0){

	// 	int newPosX, newPosY;		
	// 	switch (direction){

	// 		case 0 : // right
	// 			newPosX = pacman_->getPosX()+modifiedSpeed;
	// 			newPosY = pacman_->getPosY();
	// 			break; 

	// 		case 1 :  // left
	// 			newPosX = pacman_->getPosX()-modifiedSpeed;
	// 			newPosY = pacman_->getPosY();
	// 			break;

	// 		case 2 :  //up
	// 			newPosX = pacman_->getPosX();
	// 			newPosY = pacman_->getPosY()-modifiedSpeed;
	// 			break;

	// 		case 3 : //down
	// 			newPosX = pacman_->getPosX();
	// 			newPosY = pacman_->getPosY()+modifiedSpeed;
	// 			break;
	// 	}

	// 	// if(newPosX>=680){
	// 	// 	changePosition(0, newPosY);	
	// 	// 	modified=true;
	// 	// }

	// 	// else if (newPosX<=0){
	// 	// 	changePosition(680, newPosY);
	// 	// 	modified=true;
	// 	// }

	// 	// if(newPosY>=750){
	// 	// 	changePosition(newPosX, 0);
	// 	// 	modified=true;
	// 	// }

	// 	// else if(newPosY<=0){
	// 	// 	changePosition(newPosX, 750);
	// 	// 	modified=true;
	// 	// }

		
	// 	if( !checkColision(newPosX,newPosY)){
	// 			pacman_->setDirection(direction);
	// 			modified=true;
	// 	}	
				
	// 	--modifiedSpeed;
	// }

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

			if(charMapElement == 'p'){
				pacman_ = shared_ptr<Character>(new Pacman((char*)"sprites/pacmanClose.bmp",5,c*sizeSprite,l*sizeSprite,renderer_)); 
				//pacman_ = shared_ptr<Character>(new SpeededCharacter(pacman_));				
				charMapElement = '0';
			}

			else if(isalpha(charMapElement)){
				ghosts_.push_back(ghostFactory_->createGhost(charMapElement,c,l,sizeSprite,renderer_));
				charMapElement = '0';
			}

			mapElements_[l].push_back(mapElementFactory_->createMapElement(charMapElement,c,l,sizeSprite,renderer_));			
		}
	}
}

void GameEngine::renderMap(){
	Bonus* bonus;
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

void GameEngine::destroySDL(){

	for (unsigned int l = 0; l < mapElements_.size(); ++l){
		for (unsigned int c = 0; c < mapElements_[0].size(); ++c){
			mapElements_.at(l).at(c)->destroySDLElements();
		}
	}


	SDL_DestroyRenderer(renderer_); 
	pacman_->destroySDLElements();

	for(unsigned int i=0;i<ghosts_.size();++i){
		ghosts_.at(i)->destroySDLElements();
	}

	SDL_DestroyTexture(gameOverTexture_);
	SDL_FreeSurface(gameOverSurface_);

	SDL_DestroyTexture(playerScoreTexture_);
	SDL_FreeSurface(playerScoreSurface_);

    SDL_DestroyWindow(window_);



}



void GameEngine::renderGameOverMessage(){
	
	gameOverSurface_ = TTF_RenderText_Solid(fontGameOver_, "GAME OVER", red_); 

	gameOverTexture_ = SDL_CreateTextureFromSurface(renderer_, gameOverSurface_); 

	gameOverRect_ = {150,250,400,200};

	SDL_RenderCopy(renderer_, gameOverTexture_, NULL, &gameOverRect_); 
}





void GameEngine::renderPlayerScore(){	

	const char* score = (string("Score : ")+to_string(playerScore_)).c_str();

	playerScoreSurface_ = TTF_RenderText_Solid(fontScoring_, score, white_); 

	playerScoreTexture_ = SDL_CreateTextureFromSurface(renderer_, playerScoreSurface_); 	
	
	SDL_RenderCopy(renderer_, playerScoreTexture_, NULL, &playerScoreRect_); 
	
}


void GameEngine::checkBonusEating(){
	Bonus* actualBonus = getMapElement(pacman_->getPosX()/sizeSprite, pacman_->getPosY()/sizeSprite)->getBonus();
	if(actualBonus != nullptr){
		if(checkColisionSDLRect(pacman_->getTextureRect(), actualBonus->getTextureRect())){
			playerScore_+=actualBonus->getPoint();
			getMapElement(pacman_->getPosX()/sizeSprite, pacman_->getPosY()/sizeSprite)->eatBonus();
		}
	}
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
        while(!quit && !gameOver_){   

            while (SDL_PollEvent(&events)) {

                if(events.window.event == SDL_WINDOWEVENT_CLOSE)
                    quit = true;

                // arrow key events
                switch( events.key.keysym.sym ){ 
                    case SDLK_UP: 
                        changePacmanDirection(2);
                        break;
                    case SDLK_DOWN:
                        changePacmanDirection(3);
                        break;
                    case SDLK_RIGHT:
                        changePacmanDirection(0);
                        break;
                    case SDLK_LEFT:
                        changePacmanDirection(1);
                        break;

                  }           
              }
            moveCharacters(); 
            clearRenderer();
            renderMap(); 
            renderCharacters();
            renderPlayerScore();
            renderPresent();
            checkAllCharactersColision();
                       
            


            if(gameOver_){
            	renderGameOverMessage();
            	renderPresent();
            	SDL_Delay(5000);
            }




            //Thread test
            //std::this_thread::sleep_for (std::chrono::milliseconds(25));   

            //SDL_Delay(25);       



        }   

        destroySDL();
}