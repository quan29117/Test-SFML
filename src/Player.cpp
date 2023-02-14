#include <headers/Player.hpp>

namespace saigo {
void Player::initPlayer() {
    //Load texture and set for the player
    if (!this->player_texture.loadFromFile("res/image/Player.png")) {
        std::cout << "Load Player Failed\n";
        exit(EXIT_FAILURE);
    }
    this->player_sprite.setTexture(this->player_texture);

    //Resize + Set Position
    this->player_sprite.setScale(0.1f, 0.1f);
    this->player_sprite.setPosition( 0, 540 - this->player_sprite.getGlobalBounds().height / 2);
} 

Player::Player() {
    this->initPlayer();
}

Player::~Player() {

}

void Player::update() {

}

void Player::render(sf::RenderTarget &target) {
    target.draw(this->player_sprite);
}
}