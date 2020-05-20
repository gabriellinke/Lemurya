#pragma once
#include "Lista.h"
#include "BolaDeFogo.h"

class ListaProjeteis
{
private:
    vector<BolaDeFogo*> LTProjeteis;
public:
    ListaProjeteis();
    ~ListaProjeteis();

    vector<BolaDeFogo*> getLTProjeteis();

    void Draw(sf::RenderWindow& window);

    void limpaLista();
    void incluir(BolaDeFogo* pp);
    void retirar(const int i);
};

