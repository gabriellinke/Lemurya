#pragma once
#include "Entidade.h"
#include "Lemurya.h"
#include "State.h"
#define MAX_NUMBER_ITEMS 4

class Menu: public State, public Entidade
{
protected:
    int selectedItem;
    int num_de_itens;
    Lemurya* jogo;

    sf::Font font;
    sf::Font font2;
    sf::Text menu[MAX_NUMBER_ITEMS];
    sf::Color cor1;
    sf::Color cor2;
    sf::Text tituloDoJogo;
    sf::Texture textura1;
    sf::RectangleShape LogoDoJogo;
    sf::RectangleShape* body;

    sf::View viewMenu;
    sf::Event event;

public:
    Menu(Lemurya* jogo);
    ~Menu();
    //Métodos de Entidade
	void executar(float deltaTime);
	void destruir();
	void Draw(sf::RenderWindow& window);
	//Métodos de State
	void draw() = 0;
	void input() = 0;
	void update() = 0;

	///void inicializar();

	void MoveUp();
	void MoveDown();
	const int getPressedItem() const ;
};
