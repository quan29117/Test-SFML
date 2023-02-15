#pragma once

#include <headers/Gameplay.hpp>

/**
    Class Game for game engine
    - window
    - events
    - render
*/

namespace saigo {
class Game {
private:
//Members
    //Window
    sf::RenderWindow *window;
    sf::Event event;

    //Gameplay
    saigo::Gameplay *game_play;

//Private Functions
    void initWindow();
    void initGamePlay();

public:
//Constructor - Destructor
    Game();
    virtual ~Game();

//Getter - Setter
    bool isOpen();

//Functions
    void pollEvent();
    void update();
    void render();
};    
}
