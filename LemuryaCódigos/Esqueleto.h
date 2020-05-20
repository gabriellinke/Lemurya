#pragma once
#include "Inimigo.h"

class Esqueleto: public Inimigo
{
private:

public:
    Esqueleto(const vector<sf::Texture> textureEsqueleto, const vector<sf::Vector2u> vecEsqueleto, const sf::Vector2f posicao, Fase* pFase, const int ID = 6);
    Esqueleto(const Esqueleto& other, float x, float y);
    ~Esqueleto();

    Esqueleto* clone(const float x, const float y) const;

    void inicializa(const vector<sf::Texture> textureEsqueleto, const vector<sf::Vector2u> vecEsqueleto, const sf::Vector2f posicao, Fase* pFase, const int ID = 6);

    void executar(float deltaTime);

};

