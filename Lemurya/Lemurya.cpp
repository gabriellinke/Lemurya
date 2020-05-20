#include "Lemurya.h"
#include "MenuPrincipal.h"

Lemurya::Lemurya()
{
    p2 = false;
	this->inicializar();
	this->inicializarStates();
	deltaTime = 0;
	salvarFase1 = 0;
	salvarFase2 = 0;
	salvarFase3 = 0;
}
Lemurya::~Lemurya()
{
	while (!states.empty())
		popState();
}

void Lemurya::pushState(State* state)
{
	states.push(state);
}

void Lemurya::popState()
{
	this->states.top();
    this->states.pop();
}

State* Lemurya::stateAtual()
{
	if (states.empty())
		return nullptr;
	else
		return states.top();
}

void Lemurya::inicializar()
{
	window.create(sf::VideoMode(1280.0f, 720.0f), "Lemurya");
	window.setFramerateLimit(60);

	sf::Image icon;
	icon.loadFromFile("data/sprites/LemuryaIcon.JPG");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    player1.inicializa(200.0f, 200.0f, gerenciadorGrafico.getTexturePlayer1(), gerenciadorGrafico.getVecPlayer1(), 0.2f);
    player2.inicializa(200.0f, 200.0f, gerenciadorGrafico.getTexturePlayer1(), gerenciadorGrafico.getVecPlayer1(), 0.2f, true);///PLAYER2
}

void Lemurya::inicializarStates()
{
	states.push(new MenuPrincipal(this));
}

void Lemurya::rodar()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1/20.0f)
            deltaTime = 1/20.0f;

		if (stateAtual() == nullptr)
			continue;

		//Pega os inputs do state atual
		stateAtual()->input();

		//Atualiza o state atual
		stateAtual()->update();

		//clear window
		window.clear();

		//draw anything in the current game state
		stateAtual()->draw();

		window.display();
	}

}

void Lemurya::encerrar()
{
}

const GerenciadorGrafico Lemurya::getGerenciadorGrafico() const
{
    return gerenciadorGrafico;
}

Player* Lemurya::getPlayer1()
{
    return &(player1);
}

Player* Lemurya::getPlayer2()///PLAYER2
{
    return &(player2);
}

const bool Lemurya::getP2() const
{
    return p2;
}

void Lemurya::setP2(const bool bp)
{
    p2 = bp;
}

const bool Lemurya::getSalvarFase1() const
{
    return salvarFase1;
}

const bool Lemurya::getSalvarFase2() const
{
    return salvarFase2;
}

const bool Lemurya::getSalvarFase3() const
{
    return salvarFase3;
}

void Lemurya::setSalvarFase1(const bool b)
{
    salvarFase1 = b;
}

void Lemurya::setSalvarFase2(const bool b)
{
    salvarFase2 = b;
}

void Lemurya::setSalvarFase3(const bool b)
{
    salvarFase3 = b;
}

void Lemurya::setGanharJogo(const bool b)
{
    ganharJogo = b;
}

const bool Lemurya::getGanharJogo() const
{
    return ganharJogo;
}
