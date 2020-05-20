#pragma once
#include "Obstaculo.h"

class Pedra: public Obstaculo
{
private:

public:
    Pedra(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso = 0.95f, const int ID = 4);
    Pedra(const Pedra& other, float x, float y);
    ~Pedra();

    void inicializa(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso = 0.95f, const int ID = 4);
    Pedra* clone(const float x, const float y) const;

    void executar(float deltaTime);
};


