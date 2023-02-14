#include <headers/Game.hpp>

using namespace saigo;

int main (int argc, char* argv[]) {
    Game game;

    //Game loop
    while (game.isOpen()) {
        //Update
        game.update();
        
        //Render
        game.render();
    }

    //End
    return 0;
}
