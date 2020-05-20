#pragma once
#include "Lista.h"
#include "Platform.h"

class ListaPlataformas
{
private:
    Lista<Platform> LTPlataformas;
public:
    ListaPlataformas();
    ~ListaPlataformas();

    void limpaLista();
    void incluir(Platform* pp);

    Platform* percorrer();
    Platform* reiniciar();
};

