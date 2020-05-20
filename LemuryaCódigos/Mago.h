#pragma once
#include "Inimigo.h"
#include "BolaDeFogo.h"

class Mago: public Inimigo
{
private:
    float coolDownAtack;
    float coolDownSpawn;
    bool spawn;
    bool atack;
    bool atacking;
    bool spawning;

public:
    Mago(const vector<sf::Texture> textureMago, const vector<sf::Vector2u> vecMago, const sf::Vector2f posicao, Fase* pFase, const int ID = 7);
    Mago(const Mago& other, float x, float y);
    ~Mago();

    Mago* clone(const float x, const float y) const;

    void inicializa(const vector<sf::Texture> textureMago, const vector<sf::Vector2u> vecMago, const sf::Vector2f posicao, Fase* pFase, const int ID = 7);

    void executar(float deltaTime);

};

