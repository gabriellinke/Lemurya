#include "Personagem.h"

Personagem::Personagem():
EntidadeColidivel()
{
   vida = 10;
}

void Personagem::setVida(const int v)
{
    vida = v;
}

int Personagem::getVida() const
{
    return vida;
}

Personagem::~Personagem()
{
}

