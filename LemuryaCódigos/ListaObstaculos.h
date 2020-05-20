#pragma once
#include "Lista.h"
#include "Obstaculo.h"

class ListaObstaculos
{
private:
    vector<Obstaculo*> LTObstaculos;
public:
    ListaObstaculos();
    ~ListaObstaculos();

    vector<Obstaculo*> getLTObstaculos();

    void limpaLista();
    void incluir(Obstaculo* po);
};


