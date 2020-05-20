#pragma once
#include <SFML/Graphics.hpp>

#include "GerenciadorDeColisoes.h"
#include "GerenciadorDePontuacao.h"
#include "GerenciadorGrafico.h"

#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include <vector>
#include <stack>
using std::vector;
#include <map>
#include <string>

#include "LemuryaPrototype.h"

#include "Lista.h"
#include "ListaPlataformas.h"
#include "ListaObstaculos.h"
#include "ListaInimigos.h"
#include "ListaEntidades.h"
#include "ListaProjeteis.h"

#include "BolaDeFogo.h"
#include "Mago.h"
#include "Tritao.h"
#include "Esqueleto.h"
#include "Player.h"
#include "Platform.h"
#include "Caixa.h"
#include "Pedra.h"

#include "State.h"

class Lemurya;

class Fase: public Entidade, public State
{
protected:
    Lemurya* jogo;

    sf::RectangleShape* body;
    GerenciadorDeColisoes gerenciadorDeColisoes;
    GerenciadorDePontuacao gerenciadorDePontuacao;
    LemuryaPrototype prototype;

    ///CRIA LISTAS
    ListaInimigos Linimigos;
    ListaPlataformas Lplataformas;
    ListaObstaculos Lobstaculos;
    ListaEntidades Lentidades;
    ListaProjeteis Lprojeteis;
public:
    Fase(const sf::Vector2f tam, Lemurya* jogo);
    virtual ~Fase();
    void destruir();

    sf::RectangleShape* getBody() const ;
    sf::RectangleShape* getPlayer1() const;
    sf::RectangleShape* getPlayer2() const;

    void lancarBolaDeFogo(int x, int y);
    void spawnarEsqueleto(int x, int y);
    const int getNInimigos();

    const ListaEntidades* getLentidades();

    void executar(float deltaTime);
    void Draw(sf::RenderWindow& window);

    void gerenciarColisoes();
    void gerenciarBarraDeVida();
    void gerenciarPontuacao();
    void gerenciarTudo();

    void updateViewEBackground(sf::View& view);

    virtual void gerarInimigos() = 0;
	virtual void gerarObstaculos() = 0;

	virtual void carregarPause() = 0;
    virtual void recuperarJogo(bool player2) = 0;
    virtual void novoJogo(bool player2) = 0;

    virtual void draw() = 0;
	virtual void input() = 0;
	virtual void update() = 0;
};


