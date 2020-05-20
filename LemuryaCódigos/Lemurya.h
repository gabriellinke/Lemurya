#pragma once
#include "Fase.h"
#include "State.h"
#include <stack>

class Lemurya {
private:

    static const float VIEW_HEIGHT;

    sf::Event eventos;

    std::stack<State*> states;
    void inicializar();
    void inicializarStates();

    sf::Clock clock;

    GerenciadorGrafico gerenciadorGrafico;

    bool salvarFase1;
    bool salvarFase2;
    bool salvarFase3;

    bool p2;    ///PARA USAR NO MENU
    bool ganharJogo;

    Player player1;
    Player player2;///PLAYER2

public:
    Lemurya();
    ~Lemurya();

    float deltaTime;            ///PECADO
    sf::RenderWindow window;    ///PECADO

    void pushState(State* state);
    void popState();
    State* stateAtual();

    void rodar();

    void encerrar();

    const bool getSalvarFase1() const;
    const bool getSalvarFase2() const;
    const bool getSalvarFase3() const;
    void setSalvarFase1(const bool b);
    void setSalvarFase2(const bool b);
    void setSalvarFase3(const bool b);

    const bool getGanharJogo() const;
    void setGanharJogo(const bool b);

    const bool getP2() const;
    void setP2(const bool bp);
    Player* getPlayer1();
    Player* getPlayer2();       ///PLAYER2
    const GerenciadorGrafico getGerenciadorGrafico() const;
};

const float VIEW_HEIGHT = 1080.0f;
