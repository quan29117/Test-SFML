#include <iostream>
#include <headers/Avatar.hpp>

namespace saigo {
    Avatar::Avatar (const std::string &name, const float &r, const float &x, const float &y) 
        : Name(name) 
    {
        Cir->setRadius(r);
        Cir->setPosition(x,y);
        Cir->setOutlineThickness(10);
        Cir->setOutlineColor(sf::Color (35,150,225,200));

        sf::Rect <float> size = this->Cir->getGlobalBounds();
        this->Cir->setOrigin(r , r);
    }
    
    Avatar::~Avatar() {
        delete Cir;
        // std::cout << "Delete Avatar " << Name << '\n';
    }
    
    sf::CircleShape Avatar::getCir() {
        return *(this->Cir);
    }

    std::string Avatar::getName() {
        return this->Name;
    }

    void Avatar::ApplyImage(const std::string &path) {
        sf::Texture *text = new sf::Texture;
        
        if (!text->loadFromFile(path)) {
            std::cout << "Load image failed\n";
            return;
        }

        this->Cir->setTexture(text);
    }

    void Avatar::Move(const float &a, const float &b) {
        this->Cir->move(a,b);
    }

    void Avatar::Rotate(const float &d) {
        this->Cir->rotate(d);
    }

    void Avatar::SetOutlineColor(const sf::Color &color) {
        this->Cir->setOutlineColor(color);
    }

    void Avatar::render(sf::RenderTarget &target) {
        target.draw( * (this->Cir) );
    }
}
