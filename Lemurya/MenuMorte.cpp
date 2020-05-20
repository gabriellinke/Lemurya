#include "MenuMorte.h"
#include "MenuPause.h"
#include "FaseAquatica1.h"
MenuMorte::MenuMorte(Lemurya* jogo):
Menu(jogo)
{
	this->jogo = jogo;
	this->inicializar();
}

MenuMorte::~MenuMorte()
{
}

void MenuMorte::draw()
{
	jogo->window.draw(*body);
	jogo->window.draw(tituloDoJogo);
	jogo->window.draw(titulo);
	jogo->window.draw(entradaDeTexto);
	int i;
	for (i = 0; i < 2; i++) {

		jogo->window.draw(menu[i]);
	}
}

void MenuMorte::input()
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
			else if (event.key.code == sf::Keyboard::W && menuAtivado) {
				this->MoveUp();
			}
			else if (event.key.code == sf::Keyboard::S && menuAtivado) {
				this->MoveDown();
			}
			else if (event.key.code == sf::Keyboard::Enter) {

				if (getPressedItem()==0 && menuAtivado){
					jogo->popState();
					jogo->popState();
					break;
				}
				else if (getPressedItem()==1 && menuAtivado){
                    jogo->window.close();
					break;
				}
				else {
                    gravarRanking();
                    menuAtivado = true;
                    break;
				}

			}
			break;
        case sf::Event::TextEntered:
            if(!menuAtivado){
                if (event.text.unicode == '\b' && nome.getSize() != 0) {
                    nome.erase(nome.getSize() - 1, 1);
                }
                else if (event.text.unicode < 128) {
                    nome += event.text.unicode;
                    entradaDeTexto.setString(nome);
                }
                break;
            }
		}
	}
}

void MenuMorte::update()
{
	jogo->window.setView(viewMenu);
}

void MenuMorte::inicializar()
{
	viewMenu.setSize(jogo->window.getSize().x, jogo->window.getSize().y);
	viewMenu.setCenter(jogo->window.getSize().x / 2, jogo->window.getSize().y / 2);

    font    = jogo->getGerenciadorGrafico().getFontBlackCastle();
	font2   = jogo->getGerenciadorGrafico().getFontGameOver();
    texture = jogo->getGerenciadorGrafico().getMenuMorteTexture();

	//Define a cor do texto
	cor1.r = 6;
	cor1.g = 59;
	cor1.b = 255;

	//Define a cor do título
	cor2.r = 1;
	cor2.g = 8;
	cor2.b = 34;

    menuAtivado = false;

    num_de_itens = 2;
	//Opções do Menu
	menu[0].setFont(font);
	menu[0].setString("Back to Menu");
	menu[0].setFillColor(cor1);
	menu[0].setStyle(sf::Text::Style::Bold);
	menu[0].setPosition(sf::Vector2f(jogo->window.getSize().x -400.0, 500.0));

	menu[1].setFont(font);
	menu[1].setString("Exit");
	menu[1].setFillColor(sf::Color::White);
	menu[1].setPosition(sf::Vector2f(jogo->window.getSize().x -400.0, 600.0));

	entradaDeTexto.setFont(font);
	entradaDeTexto.setFillColor(sf::Color::White);
	entradaDeTexto.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 300.0, 400.0));

	titulo.setFont(font);
	titulo.setString("Player Name");
	titulo.setFillColor(sf::Color::White);
	titulo.setCharacterSize(40);
	titulo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 300, 300.0));

    if(!jogo->getGanharJogo()){
        tituloDoJogo.setFont(font2);
        tituloDoJogo.setString("GAME OVER");
        tituloDoJogo.setFillColor(cor2);
        tituloDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 300, -100.0));
        tituloDoJogo.setCharacterSize(300);
    }
    else
    {
        tituloDoJogo.setFont(font);
        tituloDoJogo.setString("YOU WIN");
        tituloDoJogo.setFillColor(cor1);
        tituloDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 150, 50.0));
        tituloDoJogo.setCharacterSize(100);
        jogo->setGanharJogo(false);
    }


	body = new sf::RectangleShape();
	body->setTexture(&texture);
	body->setSize(sf::Vector2f(jogo->window.getSize().x, jogo->window.getSize().y));
	body->setPosition(body->getSize() / 2.0f);
	body->setOrigin(body->getSize() / 2.0f);

	selectedItem = 0;
}

void MenuMorte::gravarRanking()
{
    FILE* Gravador = fopen("data/saves/Ranking.txt", "a+");

    nomestr = nome.substring(0, 128);
    fseek(Gravador, 0, SEEK_END);
    if(nomestr.empty())
        nomestr = "JogadorSemNome";
    fprintf(Gravador, "\n%s %d", nomestr.c_str(), (jogo->getPlayer1()->getRanking() + jogo->getPlayer2()->getRanking()));
}
