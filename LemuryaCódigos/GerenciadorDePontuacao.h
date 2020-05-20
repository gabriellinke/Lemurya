#pragma once
#include <SFML/Graphics.hpp>

#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>

class Lemurya;

class GerenciadorDePontuacao
{
private:
    Lemurya* jogo;
    sf::Text Rank;
    sf::Font font;
    std::string playerRank;
    int pontuacao;

public:
    GerenciadorDePontuacao();
    GerenciadorDePontuacao(Lemurya* j);
    ~GerenciadorDePontuacao();

    void inicializa(Lemurya* j);
    void destruir();

    void executar();

    void setPontuacao(const int pont);
    void incrementarPontuacao(const int pont);
    const int getPontuacao() const;

    void draw();
};
