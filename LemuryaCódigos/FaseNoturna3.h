#pragma once
#include "Fase.h"

class FaseNoturna3 : public Fase
{
private:
	sf::View view;
	float spawnInimigo;
	Mago* boss;
public:
	FaseNoturna3(const sf::Vector2f tam, Lemurya* jogo, const bool newGame = true, const bool player2 = false, const int pont = 0);
	~FaseNoturna3();

	void draw();
	void input();
	void update();
	void inicializar(const bool player2 = false);
	void carregar(const bool player2 = false);

	void carregarPause();
	void carregarMorte();
    void carregarProxFase();

    void gerarInimigos();
	void gerarObstaculos();

	void checkFimDeJogo();
	void checkSalvarJogo();
    void checkPlayerVivo();

    void recuperarJogo(const bool player2 = false);
    void novoJogo(const bool player2 = false);
};


