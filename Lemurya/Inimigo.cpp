#include "Inimigo.h"
#include "Fase.h"

Inimigo::Inimigo():
Personagem()
{
    fase = NULL;
}

Inimigo::~Inimigo()
{
    fase = NULL;
}

