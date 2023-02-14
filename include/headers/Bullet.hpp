#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/**
    Class for Bullet
 */
namespace saigo {
class Bullet_Player {
private:
//Members
    sf::Sprite bullet_sprite;
    sf::Texture bullet_texture;
    char char_input;

//Parameters
    sf::Vector2f direction;
    float m_speed;

//Private Functions
    void initBullet();

public:
//Constructor - Destructor
    // Bullet_Player();
    Bullet_Player(const char &ch, const float &dir_x, const float &dir_y);
    virtual ~Bullet_Player();

//Getter - Setter
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    char getCharInput();
    
//Functions
    void update();
    void render(sf::RenderTarget &target);

};
}