#include "Entidade.h"

Entidade::Entidade()
{
    x = 0;
    y = 0;
}

Entidade::~Entidade()
{
}

void Entidade::setX(const int X)
{
    x = X;
}

void Entidade::setY(const int Y)
{
    y = Y;
}

void Entidade::setID(const int ID)
{
    id = ID;
}

const int Entidade::getX() const
{
    return x;
}

const int Entidade::getY() const
{
    return y;
}

const int Entidade::getID() const
{
    return id;
}

int Entidade::getVida() const
{
    return 1;
}

