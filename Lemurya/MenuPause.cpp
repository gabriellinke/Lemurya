#include "MenuPause.h"
#include "FaseAquatica1.h"
#include "MenuPrincipal.h"

MenuPause::MenuPause(Lemurya* jogo):
Menu(jogo)
{
	this->jogo = jogo;
	this->inicializar();
}

MenuPause::~MenuPause()
{
}

void MenuPause::draw()
{
	jogo->window.draw(*body);
	jogo->window.draw(tituloDoJogo);
	jogo->window.draw(LogoDoJogo);
	int i;
	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {

		jogo->window.draw(menu[i]);
	}
}

void MenuPause::input()
{
	while (jogo->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Fecha a Janela */
		case sf::Event::Closed:
			jogo->window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				jogo->window.close();
			else if (event.key.code == sf::Keyboard::Up) {
				this->MoveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				this->MoveDown();
			}
			else if (event.key.code == sf::Keyboard::W) {
				this->MoveUp();
			}
			else if (event.key.code == sf::Keyboard::S) {
				this->MoveDown();
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				switch (getPressedItem())
				{
				case 0:
					jogo->popState();
					break;
				case 1:
					jogo->popState();
					jogo->setSalvarFase1(true);
					jogo->setSalvarFase2(true);
					jogo->setSalvarFase3(true);
					break;
				case 2:
					voltarAoMenu();
					break;
				case 3:
					jogo->window.close();
					break;
				}
			}
			break;

		}
	}
}

void MenuPause::update()
{
    jogo->window.setView(viewMenu);
}

void MenuPause::inicializar()
{

    viewMenu.setSize(jogo->window.getSize().x, jogo->window.getSize().y);
    viewMenu.setCenter(jogo->window.getSize().x/2, jogo->window.getSize().y/2);

    font    = jogo->getGerenciadorGrafico().getFontBlackCastle();
	font2   = jogo->getGerenciadorGrafico().getFontAudiowide();
    texture = jogo->getGerenciadorGrafico().getMenuPauseTexture();
    textura1 = jogo->getGerenciadorGrafico().getLogoTexture();

	num_de_itens = MAX_NUMBER_ITEMS;
	//Define a cor do texto
	cor1.r = 6;
	cor1.g = 59;
	cor1.b = 255;

	//Define a cor do título
	cor2.r = 6;
	cor2.g = 59;
	cor2.b = 103;


	//Opções do Menu
	menu[0].setFont(font);
	menu[0].setString("Resume");
	menu[0].setFillColor(cor1);
	menu[0].setStyle(sf::Text::Style::Bold);
	menu[0].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 400.0));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Save Game");
	menu[1].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 460.0));

	menu[2].setFont(font);
	menu[2].setString("Main Menu");
	menu[2].setFillColor(sf::Color::White);
	menu[2].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 520.0));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 580.0));

	tituloDoJogo.setFont(font2);
	tituloDoJogo.setString("PAUSE");
	tituloDoJogo.setFillColor(cor2);
	tituloDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 125, 250.0));

	tituloDoJogo.setCharacterSize(80);

	LogoDoJogo.setSize(sf::Vector2f(200.0f, 200.0f));
	LogoDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 65, 50.0f));
	LogoDoJogo.setTexture(&textura1);

	body = new sf::RectangleShape();
	body->setTexture(&texture);
	body->setSize(sf::Vector2f(jogo->window.getSize().x, jogo->window.getSize().y));
	body->setPosition(body->getSize() / 2.0f);
	body->setOrigin(body->getSize() / 2.0f);

	selectedItem = 0;
}

void MenuPause::voltarAoMenu()
{
	jogo->pushState(new MenuPrincipal(jogo));
}

void MenuPause::voltarAFase()
{
	jogo->pushState(new FaseAquatica1(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT), jogo));
}
