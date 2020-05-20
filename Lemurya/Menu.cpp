#include "Menu.h"
#include "MenuMorte.h"
#include "MenuPause.h"
#include "FaseAquatica1.h"

Menu::Menu(Lemurya* jogo)
{
	this->jogo = jogo;
}

Menu::~Menu()
{
	destruir();
}

void Menu::executar(float deltaTime)
{
}

void Menu::destruir()
{
	delete body;
}

void Menu::Draw(sf::RenderWindow& window)
{
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Style::Regular);
		selectedItem--;
		menu[selectedItem].setFillColor(cor1);
		menu[selectedItem].setStyle(sf::Text::Style::Bold);
	}
}

void Menu::MoveDown()
{
	if (selectedItem + 1 < num_de_itens)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Style::Regular);
		selectedItem++;

		menu[selectedItem].setStyle(sf::Text::Style::Bold);
		menu[selectedItem].setFillColor(cor1);
	}

}

const int Menu::getPressedItem() const
{
	return selectedItem;
}
