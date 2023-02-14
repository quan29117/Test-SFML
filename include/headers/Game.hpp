#pragma once

#include <random>
#include <vector>

#include <headers/Player.hpp>
#include <headers/Enemy.hpp>
#include <headers/Bullet.hpp>
#include <headers/Avatar.hpp>
/**
    Class Game for game engine
    - window
    - characters
    - game logic
    - events
    - render
*/

namespace saigo {
class GamePlay {
private:
//Members
    //Window
    sf::RenderWindow *window;
    sf::Event event;

    //Characters
    Player *player;
    std::vector <AbstractEnemy*> enemies;
    
    //Bullet
    std::vector <Bullet_Player*> bullet_player;

    //Word


//Game logic        - TODO
    //Progress
    size_t stageNumber;
        //time

    //Catch the char if typing successfully
    char getInput;

    //Spawning Enemies
    size_t RNG();
    size_t enemyNumberMax;
    // std::vector < sf::Vector2f > spawnPos;

//Private Functions
    void initWindow();
    void initObjects();

public:
//Constructor - Destructor
    GamePlay();
    virtual ~GamePlay();

//Getter - Setter
    bool isOpen();

//Functions
    void pollEvent();
    void update();
    void updatePlayer();
    void updateEnemy();
    void updateBullet();
    void playerFire();
    void collisionP_E();
    void spawnEnemy();

    void render();

//Delete after testing for loop - TODO
    saigo::Avatar *av;
    void updateAvatar();
};    
}
