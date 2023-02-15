#include <headers/Game.hpp>

namespace saigo {
//Private Functions
void Game::initWindow() {
    this->window = new sf::RenderWindow (sf::VideoMode (1920,1080), "Game", sf::Style::Default);
    this->window->setFramerateLimit(144);
    this->window->setKeyRepeatEnabled(false);
}

void Game::initGamePlay() {
    this->game_play = new saigo::Gameplay ();
}

//Constructor - Destructor
Game::Game() {
//Init members
    this->initWindow();
    this->initGamePlay();
}

Game::~Game() {
    delete this->window;
    delete this->game_play;
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
                    this->game_play->getCharInput(event.text.unicode);
                }
                break;
        }
    }
}

void Game::update() {
    this->pollEvent();
    this->game_play->update();
}

void Game::render() {
    this->window->clear();

    //Draw objects
    this->game_play->render( * (this->window));


    this->window->display();
}
}