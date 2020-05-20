#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;

using std::cout;
using std::endl;

template<typename TIPO>
class Lista
{
public:

    class Elemento
    {
        private:
            Elemento* pProximo;
            Elemento* pAnterior;
            TIPO* pInfo;

        public:
            Elemento();
            ~Elemento();

            void setProximo(Elemento* pp);
            Elemento* getProximo();

            void setAnterior(Elemento* pa);
            Elemento* getAnterior();

            void setInfo(TIPO* pi);
            TIPO* getInfo();
    };

private:
    Elemento* pPrimeiro;
    Elemento* pAtual;

    Elemento* pPercorrimento;

public:
    Lista();
    ~Lista();

    void inicializa();
    void limpar();

    bool incluaElemento(Elemento* pElemento);
    bool incluaInfo(TIPO* pInfo);
    void listeInfos();

    void setpPercorrimento(Elemento* p);

    Elemento* getpPrimeiro();
    Elemento* getpAtual();
    Elemento* getpPercorrimento();

};

template<typename TIPO>
Lista<TIPO>::Lista()
{
    inicializa();
}

template<typename TIPO>
Lista<TIPO>::~Lista()
{
    limpar();
}

template<typename TIPO>
void Lista<TIPO>::limpar()
{
    Elemento* paux1;
    Elemento* paux2;

    paux1 = pPrimeiro;
    paux2 = paux1;

    while (paux1 != NULL)
    {
        paux2 = paux1->getProximo();
        delete (paux1);
        paux1 = paux2;
    }

    pPrimeiro = NULL;
    pAtual = NULL;
    pPercorrimento = NULL;
}

template<typename TIPO>
void Lista<TIPO>::inicializa()
{
    pPrimeiro = NULL;
    pAtual = NULL;
    pPercorrimento = NULL;
}

template<typename TIPO>
bool Lista<TIPO>::incluaElemento(Elemento* pElemento)
{
    if (NULL != pElemento)
    {
        if (NULL == pPrimeiro)
        {
            pPrimeiro = pElemento;
            pPercorrimento = pPrimeiro;
            pAtual = pPrimeiro;
        }
        else
        {
            pElemento->setAnterior(pAtual);
            pElemento->setProximo(NULL);
            pAtual->setProximo(pElemento);
            pAtual = pElemento;
        }
        return true;
    }
    else
    {
        cout << " Erro, elemento nulo na lista. " << endl;
        return false;
    }
}

template<typename TIPO>
bool Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
    if (NULL != pInfo)
    {
        Elemento* pElemento;
        pElemento = new Elemento();
        pElemento->setInfo(pInfo);
        incluaElemento(pElemento);
        return true;
    }
    else
    {
        cout << "Erro, informação nula na lista. " << endl;
        return false;
    }
}

template<typename TIPO>
typename Lista<TIPO>::Elemento* Lista<TIPO>::getpPrimeiro()
{
    return pPrimeiro;
}

template<typename TIPO>
typename Lista<TIPO>::Elemento* Lista<TIPO>::getpAtual()
{
    return pAtual;
}

template<typename TIPO>
typename Lista<TIPO>::Elemento* Lista<TIPO>::getpPercorrimento()
{
    return pPercorrimento;
}

template<typename TIPO>
void Lista<TIPO>::setpPercorrimento(Elemento* p)
{
    pPercorrimento = p;
}


template<typename TIPO>
Lista<TIPO>::Elemento::Elemento()
{
    pProximo  = NULL;
    pAnterior = NULL;
    pInfo     = NULL;
}

template<typename TIPO>
Lista<TIPO>::Elemento::~Elemento()
{
    pProximo  = NULL;
    pAnterior = NULL;
    pInfo     = NULL;
}

template<typename TIPO>
void Lista<TIPO>::Elemento::setProximo(Elemento* pp)
{
    pProximo = pp;
}

template<typename TIPO>
typename Lista<TIPO>::Elemento* Lista<TIPO>::Elemento::getProximo()
{
    return pProximo;
}

template<typename TIPO>
void Lista<TIPO>::Elemento::setAnterior(Elemento* pa)
{
    pAnterior = pa;
}

template<typename TIPO>
typename Lista<TIPO>::Elemento* Lista<TIPO>::Elemento::getAnterior()
{
    return pAnterior;
}

template<typename TIPO>
void Lista<TIPO>::Elemento::setInfo(TIPO* pi)
{
    pInfo = pi;
}

template<typename TIPO>
TIPO* Lista<TIPO>::Elemento::getInfo()
{
    return pInfo;
}

