#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace saigo {
    class Avatar {
    private:
        std::string Name;
    public:sf::CircleShape *Cir = new sf::CircleShape;
        Avatar() = default;

        Avatar (const std::string &name, const float &r, const float &x, const float &y);
    
        virtual
        ~Avatar ();

        sf::CircleShape getCir();
        std::string getName();

        void ApplyImage(const std::string &path);

        void Move(const float &a, const float &b);

        void Rotate(const float &d);

        void SetOutlineColor(const sf::Color &color);

        void render(sf::RenderTarget &target);
    };
}
