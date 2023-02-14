#include <headers/Enemy.hpp>

namespace saigo {

//Start Enemy_Mob
void Enemy_Mob::initSprite() {
    if (!this->enemy_texture.loadFromFile("res/image/Enemy_Mob.png")) {
        std::cout << "Load Enemy Failed\n";
        exit(EXIT_FAILURE);
    }
    this->enemy_texture.setSmooth(true);
    this->enemy_sprite.setTexture(this->enemy_texture);

    //Resize
    this->enemy_sprite.setScale(0.8f, 0.8f);
}

void Enemy_Mob::initText() {
    //Font
    this->font.loadFromFile("res/font/specify.ttf");

    //Text
    this->text_display.setFont(this->font);
    this->text_display.setFillColor(sf::Color::Red);
}

Enemy_Mob::Enemy_Mob(const std::string &w, const float &x, const float &y) {
    this->initSprite();
    this->initText();

    this->typed_char_number = 0;
    this->word = w;
    this->text_display.setString(this->word);

    this->enemy_sprite.setPosition(x,y);
    this->text_display.setPosition(x,y);

    this->enemy_sprite.setOrigin(333/2, 58);
    auto bound = text_display.getGlobalBounds();
    this->text_display.setOrigin(bound.width / 2 , bound.height / 2);
}

Enemy_Mob::~Enemy_Mob() {

}

std::string Enemy_Mob::getStr() {
    return this->word;
}

int Enemy_Mob::getTCN() {
    return this->typed_char_number;
}

sf::Vector2f Enemy_Mob::getPosition() {
    return this->enemy_sprite.getPosition();
}

sf::FloatRect Enemy_Mob::getGlobalBounds() {
    return this->enemy_sprite.getGlobalBounds();
}

void Enemy_Mob::eraseFirstChar() {
    /**
        Erase the first char of word if being * fired *
     */

    if (this->word.size() >= 1)
        this->word.erase(0,1);
    this->typed_char_number--;  //FIX


}

void Enemy_Mob::increase_TCN() {
    /**
        Increase the type_char_number when being * typed *
     */

    this->typed_char_number++;
}
void Enemy_Mob::update() {
    /**
        Update the remained word
    */
   
    this->text_display.setString(this->word);
}

void Enemy_Mob::render(sf::RenderTarget &target) {
    target.draw(this->enemy_sprite);
    target.draw(this->text_display);
}

//Start Enemy_Elite
void Enemy_Elite::initSprite() {
    if (!this->enemy_texture.loadFromFile("res/image/Enemy_Elite.png")) {
        std::cout << "Load Enemy Failed\n";
        exit(EXIT_FAILURE);
    }
    this->enemy_texture.setSmooth(true);
    this->enemy_sprite.setTexture(this->enemy_texture);
    this->enemy_sprite.setColor(sf::Color(255,255,255,130));

    //Resize
    this->enemy_sprite.setScale(0.7f, 0.7f);
}

void Enemy_Elite::initText() {
    //Font
    this->font.loadFromFile("res/font/specify.ttf");

    //Text
    this->text_display.setFont(this->font);
    this->text_display.setFillColor(sf::Color::White);
}

Enemy_Elite::Enemy_Elite(const std::string &w, const float &x, const float &y) {
    this->initSprite();
    this->initText();

    this->typed_char_number = 0;
    this->word = w;
    this->text_display.setString(this->word);

    this->enemy_sprite.setPosition(x,y);
    this->text_display.setPosition(x,y);

    this->enemy_sprite.setOrigin(460, 125);
    auto bound = text_display.getGlobalBounds();
    this->text_display.setOrigin(bound.width / 2 , bound.height / 2);
    
}

Enemy_Elite::~Enemy_Elite() {

}

std::string Enemy_Elite::getStr() {
    return this->word;
}

int Enemy_Elite::getTCN() {
    return this->typed_char_number;
}

sf::Vector2f Enemy_Elite::getPosition() {
    return this->enemy_sprite.getPosition();
}

sf::FloatRect Enemy_Elite::getGlobalBounds() {
    return this->enemy_sprite.getGlobalBounds();
}

void Enemy_Elite::eraseFirstChar() {
    /**
        Erase the first char of word if being typed
     */
    
    if (this->word.size() >= 1 )
        this->word.erase(0,1);
    if (this->typed_char_number > 0)
        this->typed_char_number--;
}

void Enemy_Elite::increase_TCN() {
    /**
        Increase the type_char_number when being * typed *
     */

    this->typed_char_number++;
}

void Enemy_Elite::update() {
    /**
        Update the remained word
    */
    
    this->text_display.setString(this->word);
}

void Enemy_Elite::render(sf::RenderTarget &target) {
    target.draw(this->enemy_sprite);
    target.draw(this->text_display);
}

//Start Enemy_Boss
void Enemy_Boss::initSprite() {
    if (!this->enemy_texture.loadFromFile("res/image/Enemy_Boss.png")) {
        std::cout << "Load Enemy Failed\n";
        exit(EXIT_FAILURE);
    }
    this->enemy_texture.setSmooth(true);
    this->enemy_sprite.setTexture(this->enemy_texture);
    this->enemy_sprite.setColor(sf::Color(255,255,255,255));

    //Resize
    this->enemy_sprite.setScale(0.65f, 0.65f);
}

void Enemy_Boss::initText() {
    //Font
    this->font.loadFromFile("res/font/specify.ttf");

    //Text
    this->text_display.setFont(this->font);
    this->text_display.setFillColor(sf::Color::White);
}

Enemy_Boss::Enemy_Boss(const std::string &w, const float &x, const float &y) {
    this->initSprite();
    this->initText();

    this->typed_char_number = 0;
    this->word = w;
    this->text_display.setString(this->word);

    this->enemy_sprite.setPosition(x,y);
    this->text_display.setPosition(x,y);

    this->enemy_sprite.setOrigin(910, 437);
    auto bound = text_display.getGlobalBounds();
    this->text_display.setOrigin(bound.width / 2 , bound.height / 2);
}

Enemy_Boss::~Enemy_Boss() {

}

std::string Enemy_Boss::getStr() {
    return this->word;
}

int Enemy_Boss::getTCN() {
    return this->typed_char_number;
}

sf::Vector2f Enemy_Boss::getPosition() {
    return this->enemy_sprite.getPosition();
}

sf::FloatRect Enemy_Boss::getGlobalBounds() {
    return this->enemy_sprite.getGlobalBounds();
}

void Enemy_Boss::eraseFirstChar() {
    /**
        Erase the first char of word if being typed
     */

    if (this->word.size() >= 1 )
        this->word.erase(0,1);
}

void Enemy_Boss::increase_TCN() {
    /**
        Increase the type_char_number when being * typed *
     */

    this->typed_char_number++;
}

void Enemy_Boss::update() {
    /**
        Update the remained word
    */
    
    this->text_display.setString(this->word);
}

void Enemy_Boss::render(sf::RenderTarget &target) {
    target.draw(this->enemy_sprite);
    target.draw(this->text_display);
}
}