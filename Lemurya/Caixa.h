#pragma once
#include "Obstaculo.h"

class Caixa: public Obstaculo
{
private:

public:
    Caixa(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso = 0.5f, const int ID = 3);
    Caixa(const Caixa& other, float x, float y);
    ~Caixa();

    void inicializa(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso = 0.5f, const int ID = 3);
    Caixa* clone(const float x, const float y) const;

    void executar(float deltaTime);
};

