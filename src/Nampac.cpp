#include <GameEngine.hpp>
#include <memory>

using namespace std;



int main(int argc, char **argv)
{   
    try{
        unique_ptr<GameEngine> gameEngine =  unique_ptr<GameEngine>(new GameEngine);
        gameEngine->launchNampac("map/PacMap.laby");
        SDL_Quit();
    }
        
    catch(string const& exc){
        cout<<exc;
        SDL_Quit();
        return -1;
    }     
        
    
    
    return 0;
}