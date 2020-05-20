#pragma once
#include "EntidadeColidivel.h"

class BolaDeFogo: public EntidadeColidivel
{
private:
    sf::RectangleShape* player1;
    sf::RectangleShape* player2;
    sf::Vector2f direcao;
public:
    BolaDeFogo(const sf::Texture t, const sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, const int ID = 10);
    BolaDeFogo(const BolaDeFogo& other, float x, float y);
    ~BolaDeFogo();

    BolaDeFogo* clone(const float x, const float y) const;

    void inicializa(const sf::Texture t, const sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, const int ID = 10);

    void executar(float deltaTime);

};

