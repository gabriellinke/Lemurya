#pragma once
#include "Fase.h"

class FaseAquatica1: public Fase
{
private:
	sf::View view;
	float spawnInimigo;
public:
    FaseAquatica1(const sf::Vector2f tam, Lemurya* jogo, const bool newGame = true, const bool player2 = false);
    ~FaseAquatica1();

	void draw();
	void input();
	void update();
	void inicializar(const bool player2);
	void carregar(const bool player2);
	void inicializar();
	void carregar();

	void carregarPause();
	void carregarMorte();
	void carregarProxFase();

    void checkFimDaFase();
	void checkSalvarJogo();
    void checkPlayerVivo();

	void gerarInimigos();
	void gerarObstaculos();

    void recuperarJogo(const bool player2 = false);
    void novoJogo(const bool player2 = false);

};

