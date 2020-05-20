#include "GerenciadorDePontuacao.h"
#include "Lemurya.h"

GerenciadorDePontuacao::GerenciadorDePontuacao()
{
    jogo = NULL;
}

GerenciadorDePontuacao::GerenciadorDePontuacao(Lemurya* j)
{
    inicializa(j);
}

GerenciadorDePontuacao::~GerenciadorDePontuacao()
{
    destruir();
}

void GerenciadorDePontuacao::inicializa(Lemurya* j)
{
    jogo = j;
    pontuacao = 0;
    font = jogo->getGerenciadorGrafico().getFontBlackCastle();
    Rank.setFont(font);

    Rank.setString(playerRank);
	Rank.setPosition(sf::Vector2f(300.0f, -300.0f));
	Rank.setCharacterSize(40);
}

void GerenciadorDePontuacao::destruir()
{
    jogo = NULL;
}

void GerenciadorDePontuacao::executar()
{
    std::stringstream pRank;
    pontuacao = jogo->getPlayer1()->getRanking() + jogo->getPlayer2()->getRanking();
    pRank << "Score: " << pontuacao;
    playerRank = pRank.str();
    Rank.setString(playerRank);

    Rank.setPosition(sf::Vector2f(jogo->getPlayer1()->getPosition().x + 370.0f, -300.0f));
}

void GerenciadorDePontuacao::setPontuacao(const int pont)
{
    jogo->getPlayer1()->setRanking(pont);
}

void GerenciadorDePontuacao::incrementarPontuacao(const int pont)
{
    jogo->getPlayer1()->setRanking(jogo->getPlayer1()->getRanking() + pont);
}

const int GerenciadorDePontuacao::getPontuacao() const
{
    return jogo->getPlayer1()->getRanking();
}

void GerenciadorDePontuacao::draw()
{
    jogo->window.draw(Rank);
}
