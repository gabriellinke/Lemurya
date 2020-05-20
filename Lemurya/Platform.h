#pragma once
#include "EntidadeColidivel.h"
#include "Collider.h"

class Platform: public EntidadeColidivel
{
private:
    sf::Vector2f tam;

public:
    Platform(sf::Vector2f tam, sf::Vector2f position, sf::Texture platTexture, int ID = 1);
    Platform(const Platform& other, float x, float y);
    ~Platform();

    Platform* clone(const float x, const float y) const;

    virtual void executar();
};

