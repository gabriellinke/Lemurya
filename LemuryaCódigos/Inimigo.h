#pragma once
#include "Personagem.h"

class Fase;

class Inimigo: public Personagem
{
protected:;
    Fase* fase;
public:
    Inimigo();
    virtual ~Inimigo();

    virtual void executar(float deltaTime) = 0;
};
