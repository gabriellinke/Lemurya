#pragma once
#include "Menu.h"

class MenuPrincipal: public Menu
{
private:
    bool escolhaDeJogadores;
    bool escolhaDeFases;
    int fase;
    bool ranking;
    sf::Text pontuacao[5]; ///TOP 5 JOGADORES

    bool newGame;

public:
    MenuPrincipal(Lemurya* jogo);
    ~MenuPrincipal();

    //Métodos de State
    void draw();
    void input();
    void update();

    void inicializar();

    void carregarJogo();
    void abrirEscolhaDeJogadores();
	void abrirInputNome();
	void abrirEscolhaDeFases();
    void setRanking();
};
