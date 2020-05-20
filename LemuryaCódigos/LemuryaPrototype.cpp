#include "LemuryaPrototype.h"

LemuryaPrototype::LemuryaPrototype()
{
    esqueleto   = NULL;
    mago        = NULL;
    tritao      = NULL;
    chao        = NULL;
    plataforma  = NULL;
    caixa1      = NULL;
    pedra1      = NULL;
    pedra2      = NULL;
    bolaDeFogo  = NULL;
    tronco      = NULL;
}

LemuryaPrototype::LemuryaPrototype(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1, Tronco* tc1)
{
    inicializa(c1, p1, p2, e1, m1, pf1, pf2,t1, bf1, tc1);
}

void LemuryaPrototype::inicializa(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1, Tronco* tc1)
{
    caixa1      = c1;
    pedra1      = p1;
    pedra2      = p2;
    esqueleto   = e1;
    mago        = m1;
    plataforma  = pf1;
    chao        = pf2;
    tritao      = t1;
    bolaDeFogo  = bf1;
    tronco      = tc1;
}

LemuryaPrototype::~LemuryaPrototype()
{
    esqueleto   = NULL;
    mago        = NULL;
    tritao      = NULL;
    chao        = NULL;
    plataforma  = NULL;
    caixa1      = NULL;
    pedra1      = NULL;
    pedra2      = NULL;
    bolaDeFogo  = NULL;
    tronco      = NULL;
}

Caixa* LemuryaPrototype::MakeCaixa(const float x, const float y) const
{
    return caixa1->clone(x,y);
}

Pedra* LemuryaPrototype::MakePedra(const float x, const float y) const
{
    return pedra1->clone(x,y);
}

Pedra* LemuryaPrototype::MakePedra2(const float x, const float y) const
{
    return pedra2->clone(x,y);
}

Esqueleto* LemuryaPrototype::MakeEsqueleto(const float x, const float y) const
{
    return esqueleto->clone(x,y);
}

Tritao* LemuryaPrototype::MakeTritao(const float x, const float y) const
{
    return tritao->clone(x,y);
}

Mago* LemuryaPrototype::MakeMago(const float x, const float y) const
{
    return mago->clone(x,y);
}

Platform* LemuryaPrototype::MakePlataforma(const float x, const float y) const
{
    return plataforma->clone(x,y);
}

Platform* LemuryaPrototype::MakeChao(const float x, const float y) const
{
    return chao->clone(x,y);
}

BolaDeFogo* LemuryaPrototype::MakeBolaDeFogo(const float x, const float y) const
{
    return bolaDeFogo->clone(x,y);
}

Tronco* LemuryaPrototype::MakeTronco(const float x, const float y) const
{
    return tronco->clone(x,y);
}
