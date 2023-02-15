#include <headers/Gameplay.hpp>

namespace saigo {
size_t Gameplay::RNG() {
    /**
           Random Number Renegator
     */

    std::random_device rd;  
    std::mt19937 rng(rd()); 
    std::uniform_int_distribution<int> uni(1,100);
    size_t n = uni(rng);
    return n;
}

//Private Functions
void Gameplay::initObjects() {
    this->player = new Player;
    this->enemies.push_back( new Enemy_Mob ("Saigo", 600, 20));
    this->enemies.push_back( new Enemy_Elite ("Dang Minh Quan", 1500, 600));
    // this->enemies.push_back( new Enemy_Boss ("Saigo", 
    //                          1000,   600        ));
}

//Constructor - Destructor
Gameplay::Gameplay() {
//Init members
    this->initObjects();

    //Delete after testing for loop - TODO
    this->av = new Avatar ("Eyjafjalla", 50, 100, 100);     
    this->av->ApplyImage("res/Eyja.JPG");

//Game logic
    this->stageNumber = 0;
        //time
    this->enemyNumberMax = 7;
}

Gameplay::~Gameplay() {
    delete this->player;

    for (auto &enemy : this->enemies) {
        delete enemy;
    }

    for (auto &bullet : this->bullet_player) {
        delete bullet;
    }
}

void Gameplay::getCharInput(const char &ch) {
    this->charInput = ch;
}

void Gameplay::update() {
    this->updatePlayer();
    this->updateEnemy();
    this->updateBullet();
    this->updateAvatar();
}

void Gameplay::updatePlayer() {
    this->player->update();
    this->playerFire();
}

void Gameplay::updateEnemy() {
    int index = 0;
    while (index < enemies.size()) {
        if (enemies[index]->getStr().size() < 1) enemies.erase(enemies.begin() + index);
        else index++;
    }
    
    this->collisionP_E();
    
}

void Gameplay::updateBullet() {
    for (auto &bullet: this->bullet_player) {
        bullet->update();
    }
}

void Gameplay::playerFire() {
    for (int i = 0; i < enemies.size(); i++) {
        if ( this->charInput != '\0' &&
                this->charInput == enemies[i]->getStr() [enemies[i]->getTCN()]) {
            this->bullet_player.push_back( new Bullet_Player (this->charInput, 
                                                        enemies[i]->getPosition().x, enemies[i]->getPosition().y) );
            enemies[i]->increase_TCN();
            
        }
    }
    this->charInput = '\0';
}

void Gameplay::collisionP_E() {
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

void Gameplay::spawnEnemy() {   //TODO
    //RNG for squad
    

    //push_back pos


    //push_back enemies
        //RNG words

        //
    //
}

void Gameplay::render(sf::RenderTarget &target) {

    //Draw objects
    this->player->render(target);

    for (auto &enemy : this->enemies)
        enemy->render(target);

    for (auto &bullet : this->bullet_player)
        bullet->render(target);

    this->av->render(target);        //Delete after testing for loop - TODO

}

void Gameplay::updateAvatar() {          //Delete after testing for loop - TODO
    this->av->Rotate(2.5);
}

}