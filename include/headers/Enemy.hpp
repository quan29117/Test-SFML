#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/**
    Class for Enemies
 */

class AbstractEnemy {
public:     //FIX -> private
//Members
    sf::Sprite enemy_sprite;
    sf::Texture enemy_texture;
    sf::Text text_display;
    std::string word;
    int typed_char_number;
    sf::Font font;

//Pure Virtual Functions
    virtual void initSprite() = 0;
    virtual void initText() = 0;
/*--------------------------------------------------------*/
public:
    virtual std::string getStr() = 0;
    virtual int         getTCN() = 0;
    virtual sf::Vector2f getPosition() = 0;
    virtual sf::FloatRect getGlobalBounds() = 0;

    virtual void eraseFirstChar() = 0;
    virtual void increase_TCN() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderTarget &target) = 0;
};

namespace saigo {
class Enemy_Mob : public AbstractEnemy {
private:
//Private Functions
    void initSprite();
    void initText();

public:
//Constructor - Destructor
    Enemy_Mob(const std::string &w, const float &x, const float &y);
    virtual ~Enemy_Mob();

//Getter
    std::string getStr();
    int         getTCN();
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();

//Functions
    void eraseFirstChar();
    void increase_TCN();
    void update();
    void render(sf::RenderTarget &target);
};

class Enemy_Elite : public AbstractEnemy {
private:
//Private Functions
    void initSprite();
    void initText();

public:
//Constructor - Destructor
    Enemy_Elite(const std::string &w, const float &x, const float &y);
    virtual ~Enemy_Elite();

//Getter
    std::string getStr();
    int         getTCN();
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();

//Functions
    void eraseFirstChar();
    void increase_TCN();
    void update();
    void render(sf::RenderTarget &target);

};

class Enemy_Boss : public AbstractEnemy {
private:
//Private Functions
    void initSprite();
    void initText();

public:
//Constructor - Destructor
    Enemy_Boss(const std::string &w, const float &x, const float &y);
    virtual ~Enemy_Boss();

//Getter
    std::string getStr();
    int         getTCN();
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    
//Functions
    void eraseFirstChar();
    void increase_TCN();
    void update();
    void render(sf::RenderTarget &target);

};
}