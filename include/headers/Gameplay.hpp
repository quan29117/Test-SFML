#pragma once

#include <random>
#include <vector>
#include <headers/Player.hpp>
#include <headers/Enemy.hpp>
#include <headers/Bullet.hpp>
#include <headers/Avatar.hpp>

/**
    Class for game play and logic
    - characters
    - game logic
    - render
*/

namespace saigo {
class Gameplay {
private:
//Members
    //Characters
    Player *player;
    std::vector <AbstractEnemy*> enemies;
    
    //Bullet
    std::vector <Bullet_Player*> bullet_player;

//Game logic        - TODO
    //Progress
    size_t stageNumber;
        //time

    //Catch the char if typing successfully
    char charInput;

    //Spawning Enemies
    size_t RNG();
    size_t enemyNumberMax;
    // std::vector < sf::Vector2f > spawnPos;

//Private Functions
    void initObjects();

public:
//Cons - Des
    Gameplay();
    virtual ~Gameplay();

//Getter - Setter

//Functions
    void getCharInput(const char &ch);
    void update();
    void updatePlayer();
    void updateEnemy();
    void updateBullet();
    void playerFire();
    void collisionP_E();
    void spawnEnemy();
    void render(sf::RenderTarget &target);

//Delete after testing for loop - TODO
    saigo::Avatar *av;
    void updateAvatar();
};
}