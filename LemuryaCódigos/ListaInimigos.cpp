#include "ListaInimigos.h"

ListaInimigos::ListaInimigos()
{
}

ListaInimigos::~ListaInimigos()
{
    limpaLista();
}

void ListaInimigos::limpaLista()
{
    LTInimigos.clear();
}

void ListaInimigos::incluir(Inimigo* pi)
{
    if(pi)
        LTInimigos.push_back(pi);
}

vector<Inimigo*> ListaInimigos::getLTInimigos()
{
    return LTInimigos;
}

void ListaInimigos::retirar(const int i)
{
    LTInimigos.erase(LTInimigos.begin() + i);
}

const int ListaInimigos::getTamanho() const
{
    return LTInimigos.size();
}
