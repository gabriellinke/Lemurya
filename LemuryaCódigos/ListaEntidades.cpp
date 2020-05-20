#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
    limpaLista();
}

void ListaEntidades::limpaLista()
{
    LTEntidades.limpar();
}

void ListaEntidades::incluir(Entidade* pe)
{
    if(pe!=NULL)
        LTEntidades.incluaInfo(pe);
}

void ListaEntidades::Draw(sf::RenderWindow& window)
{
    Lista<Entidade>::Elemento* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();
        pEntAux->Draw(window);
        pElAux = pElAux->getProximo();
    }
}

void ListaEntidades::retirar()
{
    Lista<Entidade>::Elemento* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    Lista<Entidade>::Elemento* pElAnt = NULL;
    Lista<Entidade>::Elemento* pElPost = NULL;
    while (pElAux != NULL)
    {
        pEntAux = pElAux->getInfo();

        if(!pEntAux->getVida())
        {
            pElAnt = pElAux->getAnterior();
            pElPost = pElAux->getProximo();
            pElAnt->setProximo(pElPost);
            pElPost->setAnterior(pElAnt);
            break;
        }

        pElAux = pElAux->getProximo();
    }

}

void ListaEntidades::executar(float deltaTime)
{
    Lista<Entidade>::Elemento* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();
        pEntAux->executar(deltaTime);
        pElAux = pElAux->getProximo();
    }
}

Entidade* ListaEntidades::percorrer()
{
    if(LTEntidades.getpPercorrimento() != NULL)
    {
        Lista<Entidade>::Elemento* pElAux = NULL;
        Entidade* pEntAux = NULL;
        pElAux = LTEntidades.getpPrimeiro();

        pEntAux = pElAux->getInfo();

        LTEntidades.setpPercorrimento(LTEntidades.getpPercorrimento()->getProximo());

        return pEntAux;
    }

    else
        return NULL;
}

Entidade* ListaEntidades::reiniciar()
{
    LTEntidades.setpPercorrimento(LTEntidades.getpPrimeiro());
    return LTEntidades.getpPrimeiro()->getInfo();
}

void ListaEntidades::gravarJogo1()
{
    ofstream Gravador("data/saves/Fase1Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    Lista<Entidade>::Elemento* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();

        Gravador    << pEntAux->getID() << " "
                    << pEntAux->getX() << " "
                    << pEntAux->getY() << endl;

        pElAux = pElAux->getProximo();
    }

    Gravador.close();
}

void ListaEntidades::gravarJogo2()
{
    ofstream Gravador("data/saves/Fase2Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    Lista<Entidade>::Elemento* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();

        Gravador    << pEntAux->getID() << " "
                    << pEntAux->getX() << " "
                    << pEntAux->getY() << endl;

        pElAux = pElAux->getProximo();
    }

    Gravador.close();
}

void ListaEntidades::gravarJogo3()
{
    ofstream Gravador("data/saves/Fase3Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    Lista<Entidade>::Elemento* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();

        Gravador    << pEntAux->getID() << " "
                    << pEntAux->getX() << " "
                    << pEntAux->getY() << endl;

        pElAux = pElAux->getProximo();
    }

    Gravador.close();
}
