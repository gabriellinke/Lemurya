#pragma once
#include "ListaInimigos.h"
#include "ListaPlataformas.h"
#include "ListaObstaculos.h"
#include "ListaEntidades.h"
#include "ListaProjeteis.h"
#include "Player.h"

class GerenciadorDeColisoes
{
private:
    Player* player1;
    Player* player2;
    Platform* aux;
    ListaPlataformas* Lplataformas;
    ListaObstaculos* Lobstaculos;
    ListaInimigos* Linimigos;
    ListaEntidades* Lentidades;
    ListaProjeteis* Lprojeteis;
    sf::Vector2f direction;

public:
    GerenciadorDeColisoes();
    GerenciadorDeColisoes(Player* p1, Player* p2, ListaPlataformas* lp, ListaObstaculos* lo, ListaInimigos* li, ListaEntidades* le, ListaProjeteis* lproj);
    ~GerenciadorDeColisoes();

    void inicializa(Player* p1, Player* p2, ListaPlataformas* lp, ListaObstaculos* lo, ListaInimigos* li, ListaEntidades* le, ListaProjeteis* lproj);
    void destruir();

    void executar();
};

