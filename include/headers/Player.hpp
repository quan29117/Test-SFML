#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/**
    Class for Player
    - main character -
 */

namespace saigo {
class Player {
private:
//Members
    sf::Sprite player_sprite;
    sf::Texture player_texture;


//Private Functions
    void initPlayer();

public:
//Constructor - Destructor
    Player();
    virtual ~Player();

//Functions
    void update();
    void render(sf::RenderTarget &target);
};
}