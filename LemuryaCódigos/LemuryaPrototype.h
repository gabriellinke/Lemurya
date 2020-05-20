#pragma once
#include "Mago.h"
#include "Tritao.h"
#include "Esqueleto.h"
#include "BolaDeFogo.h"
#include "Platform.h"
#include "Caixa.h"
#include "Pedra.h"
#include "Tronco.h"

class LemuryaPrototype
{
private:
    Esqueleto* esqueleto;
    Mago* mago;
    Tritao* tritao;
    Platform* chao;
    Platform* plataforma;
    Caixa* caixa1;
    Pedra* pedra1;
    Pedra* pedra2;
    Tronco* tronco;
    BolaDeFogo* bolaDeFogo;
public:
    LemuryaPrototype(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1, Tronco* tc1);
    LemuryaPrototype();
    ~LemuryaPrototype();
    void inicializa(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1, Tronco* tc1);

    Caixa* MakeCaixa(const float x, const float y) const;
    Esqueleto* MakeEsqueleto(const float x, const float y) const;
    Mago* MakeMago(const float x, const float y) const;
    Tritao* MakeTritao(const float x, const float y) const;
    Platform* MakeChao(const float x, const float y) const;
    Platform* MakePlataforma(const float x, const float y) const;
    Pedra* MakePedra(const float x, const float y) const;
    Pedra* MakePedra2(const float x, const float y) const;
    BolaDeFogo* MakeBolaDeFogo(const float x, const float y) const;
    Tronco* MakeTronco(const float x, const float y) const;
};

