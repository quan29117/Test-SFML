#include <headers/Game.hpp>

namespace saigo {
//Private Functions
void Game::initWindow() {
    this->window = new sf::RenderWindow (sf::VideoMode (1920,1080), "Game", sf::Style::Default );
    this->window->setFramerateLimit(90);
    this->window->setKeyRepeatEnabled(false);
}

void Game::initObjects() {
    this->player = new Player;
    // this->enemies.push_back( new Enemy_Mob ("Saigo", 600, 20));
    // this->enemies.push_back( new Enemy_Elite ("Dang Minh Quan", 1500, 600));
    // this->enemies.push_back( new Enemy_Boss ("Saigo", 
    //                          1000,   600        ));
}

size_t Game::RNG() {
    /**
           Random Number Renegator
     */

    std::random_device rd;  
    std::mt19937 rng(rd()); 
    std::uniform_int_distribution<int> uni(1,100);
    size_t n = uni(rng);
    return n;
}

//Constructor - Destructor
Game::Game() {
//Init members
    this->initWindow();
    this->initObjects();

    //Delete after testing for loop - TODO
    this->av = new Avatar ("Eyjafjalla", 50, 100, 100);     
    this->av->ApplyImage("res/Eyja.JPG");

//Game logic
    this->stageNumber = 0;
        //time
    this->enemyNumberMax = 7;
}

Game::~Game() {
    delete this->window;
    delete this->player;

    for (auto &enemy : this->enemies) {
        delete enemy;
    }

    for (auto &bullet : this->bullet_player) {
        delete bullet;
    }
}

//Getter - Setter
bool Game::isOpen() {
    return this->window->isOpen();
}

//Functions
void Game::pollEvent() {
    /**
        Polling Event each loop of Gameplay    
     */

    while (this->window->pollEvent(this->event)) {
        switch (event.type) {
            case sf::Event::Closed :
                this->window->close();
                break;

            case sf::Event::KeyPressed :
                if (event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            
            case sf::Event::TextEntered :
                if (event.text.unicode < 128) {
                    this->getInput = event.text.unicode;
                }
                break;
        }
    }
}

void Game::update() {
    this->updatePlayer();
    this->updateEnemy();
    this->updateBullet();
    this->updateAvatar();
}

void Game::updatePlayer() {
    this->player->update();
    this->playerFire();
}

void Game::updateEnemy() {
    int index = 0;
    while (index < enemies.size()) {
        if (enemies[index]->getStr().size() < 1) enemies.erase(enemies.begin() + index);
        else index++;
    }
    
    this->collisionP_E();
    
}

void Game::updateBullet() {
    for (auto &bullet: this->bullet_player) {
        bullet->update();
    }
}

void Game::playerFire() {
    for (int i = 0; i < enemies.size(); i++) {
        if ( this->getInput != '\0' &&
                this->getInput == enemies[i]->getStr() [enemies[i]->getTCN()]) {
            this->bullet_player.push_back( new Bullet_Player (this->getInput, 
                                                        enemies[i]->getPosition().x, enemies[i]->getPosition().y) );
            enemies[i]->increase_TCN();
            
        }
    }
    this->getInput = '\0';
}

void Game::collisionP_E() {
    /**
        Collision between Player Bullet and Enemies 
      */

    if (this->enemies.size() > 0 && this->bullet_player.size() > 0) 
        for (int i = 0; i < bullet_player.size(); i++)
            for (int k = 0; k < enemies.size(); k++)
                if (bullet_player[i]->getGlobalBounds().intersects(enemies[k]->getGlobalBounds()) 
                && bullet_player[i]->getCharInput() == enemies[k]->getStr() [0]) {
                    bullet_player.erase(bullet_player.begin() + i);
                    enemies[k]->eraseFirstChar();
                    enemies[k]->update();
                }
}

void Game::spawnEnemy() {   //TODO
    //RNG for squad
    

    //push_back pos


    //push_back enemies
        //RNG words

        //
    //
}

void Game::updateAvatar() {
    this->av->Rotate(2.5);
}

void Game::render() {
    this->window->clear();

    //Draw objects
    this->player->render( * this->window);

    for (auto &enemy : this->enemies)
        enemy->render(* this->window);

    for (auto &bullet : this->bullet_player)
        bullet->render(* this->window);

    this->av->render(* this->window);        //Delete after testing for loop - TODO


    this->window->display();
}
}