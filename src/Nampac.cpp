#include <GameEngine.hpp>
#include <MapReader.hpp>
#include <vector>


#include <thread>        
#include <chrono> 

using namespace std;



int main(int argc, char **argv)
{   
    try{
        GameEngine gameEngine;
        SDL_Event events;
        bool quit(false);
        
        SDL_Window* window = gameEngine.getWindow();

        vector<vector<int>> laby = MapReader::BuildMap("map/laby1.laby");

        gameEngine.createMap(laby); 
        
        // While window isn't close
        while(!quit){   

            while (SDL_PollEvent(&events)) {

                if(events.window.event == SDL_WINDOWEVENT_CLOSE)
                     quit = true;

                // arrow key events
                switch( events.key.keysym.sym ){ 
                    case SDLK_UP: 
                        gameEngine.changePacmanDirection(2);
                        break;
                    case SDLK_DOWN:
                        gameEngine.changePacmanDirection(3);
                        break;
                    case SDLK_RIGHT:
                        gameEngine.changePacmanDirection(0);
                        break;
                    case SDLK_LEFT:
                        gameEngine.changePacmanDirection(1);
                        break;

                  }           
              }
            gameEngine.clearRenderer();
            gameEngine.renderMap(); 
            gameEngine.renderCharacter(gameEngine.getPacman());
            gameEngine.moveCharacter(gameEngine.getPacman());
            gameEngine.renderPresent();



            //Thread test
            //std::this_thread::sleep_for (std::chrono::milliseconds(25));   

            SDL_Delay(25);       



        }   

        gameEngine.destroySDL();
        SDL_Quit();
    }
        
    catch(string const& exc){
        cout<<exc;
        SDL_Quit();
        return -1;
    }     
        
    
    
    return 0;
}