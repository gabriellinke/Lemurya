#include "ListaProjeteis.h"

ListaProjeteis::ListaProjeteis()
{
}

ListaProjeteis::~ListaProjeteis()
{
    limpaLista();
}

void ListaProjeteis::limpaLista()
{
    LTProjeteis.clear();
}

void ListaProjeteis::incluir(BolaDeFogo* pp)
{
    if(pp != NULL)
        LTProjeteis.push_back(pp);
}

vector<BolaDeFogo*> ListaProjeteis::getLTProjeteis()
{
    return LTProjeteis;
}

void ListaProjeteis::retirar(const int i)
{
    LTProjeteis.erase(LTProjeteis.begin() + i);
}

void ListaProjeteis::Draw(sf::RenderWindow& window)
{
    for(int i=0; i<LTProjeteis.size(); i++)
        LTProjeteis[i]->Draw(window);
}
