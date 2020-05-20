#pragma once
#include "Inimigo.h"

class Tritao: public Inimigo
{
private:

public:
    Tritao(const vector<sf::Texture> textureTritao, const vector<sf::Vector2u> vecTritao, const sf::Vector2f posicao, Fase* pFase, const int ID = 8);
    Tritao(const Tritao& other, float x, float y);
    ~Tritao();

    Tritao* clone(const float x, const float y) const;

    void inicializa(const vector<sf::Texture> textureTritao, const vector<sf::Vector2u> vecTritao, const sf::Vector2f posicao, Fase* pFase, const int ID = 8);

    void executar(float deltaTime);
};

