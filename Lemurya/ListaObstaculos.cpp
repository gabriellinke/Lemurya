#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos()
{
}

ListaObstaculos::~ListaObstaculos()
{
    limpaLista();
}

void ListaObstaculos::limpaLista()
{
    LTObstaculos.clear();
}

void ListaObstaculos::incluir(Obstaculo* po)
{
    if(po != NULL)
        LTObstaculos.push_back(po);
}

vector<Obstaculo*> ListaObstaculos::getLTObstaculos()
{
    return LTObstaculos;
}

