#pragma once
#include "Menu.h"
#include <string>
#include <string.h>


class MenuMorte: public Menu
{
private:
    sf::Text entradaDeTexto;
    sf::Text titulo;
    sf::String nome;
    std::string nomestr;

    bool menuAtivado;
public:
	MenuMorte(Lemurya* jogo);
	~MenuMorte();

	//Métodos de State
	void draw();
	void input();
	void update();

	void inicializar();
    void gravarRanking();
};
