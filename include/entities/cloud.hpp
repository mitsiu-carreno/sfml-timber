#ifndef CLOUD_H
#define CLOUD_H
#include <SFML/Graphics.hpp>

struct Cloud
{
    sf::Sprite spriteCloud;
    bool isActive;
    float speed;
};

#endif