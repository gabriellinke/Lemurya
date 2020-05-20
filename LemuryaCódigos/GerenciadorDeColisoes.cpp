#include "GerenciadorDeColisoes.h"

GerenciadorDeColisoes::GerenciadorDeColisoes()
{
    player1         = NULL;
    player2         = NULL;
    Lobstaculos     = NULL;
    Lplataformas    = NULL;
    Linimigos       = NULL;
    Lentidades      = NULL;
    Lprojeteis      = NULL;
    aux             = NULL;
}

GerenciadorDeColisoes::GerenciadorDeColisoes(Player* p1, Player* p2, ListaPlataformas* lp, ListaObstaculos* lo, ListaInimigos* li, ListaEntidades* le, ListaProjeteis* lproj)
{
    inicializa(p1, p2, lp, lo, li, le, lproj);
}

GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
    destruir();
}

void GerenciadorDeColisoes::destruir()
{
    player1         = NULL;
    player2         = NULL;
    Lobstaculos     = NULL;
    Lplataformas    = NULL;
    Linimigos       = NULL;
    Lentidades      = NULL;
    Lprojeteis      = NULL;
    aux             = NULL;
}

void GerenciadorDeColisoes::inicializa(Player* p1, Player* p2, ListaPlataformas* lp, ListaObstaculos* lo, ListaInimigos* li, ListaEntidades* le, ListaProjeteis* lproj)
{
    player1         = p1;
    player2         = p2;
    Lplataformas    = lp;
    Lobstaculos     = lo;
    Linimigos       = li;
    Lentidades      = le;
    Lprojeteis      = lproj;
    direction       = sf::Vector2f(0.0f, 0.0f);
}

void GerenciadorDeColisoes::executar()
{
    int i, j;

    ///COLISÕES COM AS PLATAFORMAS
    //PLAYER1
    for(aux = Lplataformas->reiniciar(); aux != NULL; aux = Lplataformas->percorrer())
        if(aux->getCollider().CheckCollision(player1->getCollider(), direction, 1.0f))
            player1->onCollision(direction);
    //PLAYER2
    for(aux = Lplataformas->reiniciar(); aux != NULL; aux = Lplataformas->percorrer())
        if(aux->getCollider().CheckCollision(player2->getCollider(), direction, 1.0f))
            player2->onCollision(direction);
    //OBSTÁCULOS
    for(aux = Lplataformas->reiniciar(); aux != NULL; aux = Lplataformas->percorrer())
        for(i=0; i < Lobstaculos->getLTObstaculos().size(); i++)
            if(aux->getCollider().CheckCollision(Lobstaculos->getLTObstaculos()[i]->getCollider(), direction, 1.0f))
                Lobstaculos->getLTObstaculos()[i]->onCollision(direction);
    //INIMIGOS
    for(aux = Lplataformas->reiniciar(); aux != NULL; aux = Lplataformas->percorrer())
        for(i=0; i < Linimigos->getLTInimigos().size(); i++)
            if(aux->getCollider().CheckCollision(Linimigos->getLTInimigos()[i]->getCollider(), direction, 1.0f))
                Linimigos->getLTInimigos()[i]->onCollision(direction);



    ///COLISÕES COM OBSTÁCULOS
    //PLAYER1
    for(i=0; i < Lobstaculos->getLTObstaculos().size(); i++)
        if(Lobstaculos->getLTObstaculos()[i]->getCollider().CheckCollision(player1->getCollider(), direction, 0.5f))      ///PESO??
            player1->onCollision(direction);
    //PLAYER2
    for(i=0; i < Lobstaculos->getLTObstaculos().size(); i++)
        if(Lobstaculos->getLTObstaculos()[i]->getCollider().CheckCollision(player2->getCollider(), direction, 0.5f))      ///PESO??
            player2->onCollision(direction);


    ///COLISÕES ENTRE OBSTÁCULOS
    for(i=0; i < Lobstaculos->getLTObstaculos().size(); i++)
        for(j=0; j < Lobstaculos->getLTObstaculos().size(); j++)
            if(i != j)
                if(Lobstaculos->getLTObstaculos()[i]->getCollider().CheckCollision(Lobstaculos->getLTObstaculos()[j]->getCollider(), direction, 0.5f))  ///PESO??
                    Lobstaculos->getLTObstaculos()[j]->onCollision(direction);



    ///COLISÕES COM INIMIGOS
    //PLAYER1
    for(i=0; i < Linimigos->getLTInimigos().size(); i++)
        if(Linimigos->getLTInimigos()[i]->getCollider().CheckCollision(player1->getCollider(), direction, 0.97f))
        {
            if(player1->isAtacking())
            {
                Linimigos->getLTInimigos()[i]->setVida(0);
                Linimigos->retirar(i);
                player1->setRanking(player1->getRanking() + 10);
            }
            else
            {
                player1->knockback(direction);
                player1->setVida(player1->getVida()-1);
                player1->getDamage()->setSize(sf::Vector2f(200 - std::max(0, (player1->getVida()*20)), 50));

            }
        }
    //PLAYER2
    for(i=0; i < Linimigos->getLTInimigos().size(); i++)
        if(Linimigos->getLTInimigos()[i]->getCollider().CheckCollision(player2->getCollider(), direction, 0.97f))
        {
            if(player2->isAtacking())
            {
                Linimigos->getLTInimigos()[i]->setVida(0);
                Linimigos->retirar(i);
                player2->setRanking(player2->getRanking() + 10);
            }
            else
            {
                player2->knockback(direction);
                player2->setVida(player2->getVida()-1);
                player2->getDamage()->setSize(sf::Vector2f(200 - std::max(0, (player2->getVida()*20)), 50));
            }
        }

    ///COLISÕES COM PROJETEIS
    //PLAYER1
    for(i=0; i < Lprojeteis->getLTProjeteis().size(); i++)
        if(Lprojeteis->getLTProjeteis()[i]->getCollider().CheckCollision(player1->getCollider(), direction, 0.97f))
        {
            player1->knockback(direction);
            player1->setVida(player1->getVida()-1);
            player1->getDamage()->setSize(sf::Vector2f(200 - std::max(0, (player1->getVida()*20)), 50));
            Lprojeteis->retirar(i);
        }
    //PLAYER2
    for(i=0; i < Lprojeteis->getLTProjeteis().size(); i++)
        if(Lprojeteis->getLTProjeteis()[i]->getCollider().CheckCollision(player2->getCollider(), direction, 0.97f))
        {
            player2->knockback(direction);
            player2->setVida(player2->getVida()-1);
            player2->getDamage()->setSize(sf::Vector2f(200 - std::max(0, (player2->getVida()*20)), 50));
            Lprojeteis->retirar(i);
        }


    ///COLISÕES ENTRE INIMIGOS
    for(i=0; i < Linimigos->getLTInimigos().size(); i++)
        for(j=0; j < Linimigos->getLTInimigos().size(); j++)
            if(i != j)
                if(Linimigos->getLTInimigos()[i]->getCollider().CheckCollision(Linimigos->getLTInimigos()[j]->getCollider(), direction, 1.0f))  ///PESO??
                    Linimigos->getLTInimigos()[j]->onCollision(direction);


    ///COLISÕES ENTRE OBSTÁCULOS E INIMIGOS
    for(i=0; i < Linimigos->getLTInimigos().size(); i++)
        for(j=0; j < Lobstaculos->getLTObstaculos().size(); j++)
            if(Linimigos->getLTInimigos()[i]->getCollider().CheckCollision(Lobstaculos->getLTObstaculos()[j]->getCollider(), direction, 0.3f))  ///PESO??
                    Lobstaculos->getLTObstaculos()[j]->onCollision(direction);
}

