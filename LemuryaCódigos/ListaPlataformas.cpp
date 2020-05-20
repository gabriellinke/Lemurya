#include "ListaPlataformas.h"

ListaPlataformas::ListaPlataformas()
{
}

ListaPlataformas::~ListaPlataformas()
{
    limpaLista();
}

void ListaPlataformas::limpaLista()
{
    LTPlataformas.limpar();
}

void ListaPlataformas::incluir(Platform* pp)
{
    if(pp!=NULL)
        LTPlataformas.incluaInfo(pp);
}

Platform* ListaPlataformas::percorrer()
{
    if(LTPlataformas.getpPercorrimento() != NULL)
    {
        Lista<Platform>::Elemento* pElAux = NULL;
        Platform* pPlatAux = NULL;
        pElAux = LTPlataformas.getpPercorrimento();

        pPlatAux = pElAux->getInfo();

        LTPlataformas.setpPercorrimento(LTPlataformas.getpPercorrimento()->getProximo());

        return pPlatAux;
    }

    else
        return NULL;
}

Platform* ListaPlataformas::reiniciar()
{
    LTPlataformas.setpPercorrimento(LTPlataformas.getpPrimeiro());
    return LTPlataformas.getpPrimeiro()->getInfo();
}

