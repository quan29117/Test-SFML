#include <math.h>
#include <headers/Bullet.hpp>



float AngleTwoVector (const sf::Vector2f &v1, const sf::Vector2f &v2) {
    float b = v1.y - v2.y;
    if (b == 0) return 0;

    float a = v2.x - v1.x;
    float cos = b*b / ( sqrt( a*a + b*b ) * b);
    return (acos(cos)) * 180 / 3.1416 ;
    
}

namespace saigo {
void Bullet_Player::initBullet() {
    //Load texture and set for the player
    if (!this->bullet_texture.loadFromFile("res/image/Player_Bullet.png")) {
        std::cout << "Load Player Failed\n";
        exit(EXIT_FAILURE);
    }
    this->bullet_sprite.setTexture(this->bullet_texture);
    

    //Resize
    this->bullet_sprite.setScale(0.35f,0.35f);

    //Position
    this->bullet_sprite.setOrigin(25,75);
    this->bullet_sprite.setPosition(350, 550);
    
    
}

// Bullet_Player::Bullet_Player() {
//     this->initBullet();
// };

Bullet_Player::Bullet_Player(const char &ch, const float &dir_x, const float &dir_y ) {
        this->initBullet();
        this->char_input = ch;

        this->direction = sf::Vector2f (dir_x, dir_y);
        this->m_speed = 0.005;
        this->bullet_sprite.rotate( AngleTwoVector (this->getPosition(), this->direction) );
    }

Bullet_Player::~Bullet_Player() {
    
}

sf::Vector2f Bullet_Player::getPosition() {
    return this->bullet_sprite.getPosition();
    this->bullet_sprite.getGlobalBounds();
}

sf::FloatRect Bullet_Player::getGlobalBounds() {
    return this->bullet_sprite.getGlobalBounds();
}

char Bullet_Player::getCharInput() {
    return this->char_input;
}

void Bullet_Player::update() {
    //Movement
    this->bullet_sprite.move(this->m_speed * ( this->direction - sf::Vector2f(300,480) ));
}

void Bullet_Player::render(sf::RenderTarget &target) {
    target.draw(this->bullet_sprite);
}
}