#include "FaseAquatica2.h"
#include "Lemurya.h"
#include "MenuMorte.h"
#include "MenuPause.h"
#include "FaseNoturna3.h"

FaseAquatica2::FaseAquatica2(const sf::Vector2f tam, Lemurya* jogo, const bool newGame, const bool player2, const int pont):
Fase(tam, jogo)
{
	texture = jogo->getGerenciadorGrafico().getFase2Texture();
    body->setTexture(&texture);
    spawnInimigo = 0;

    jogo->setSalvarFase2(false);

    if(newGame)
        inicializar(player2);
    else
        carregar(player2);

    jogo->getPlayer1()->setRanking(pont);
}

FaseAquatica2::~FaseAquatica2()
{
}

void FaseAquatica2::draw()
{
	jogo->window.draw(*body);
	gerenciadorDePontuacao.draw();
	Lentidades.Draw(jogo->window);
}

void FaseAquatica2::input()
{
	sf::Event event;

	while (jogo->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Se Sair da Janela Vai pro Pause*/
		case sf::Event::LostFocus:
			carregarPause();
			break;
			/* Fecha a Janela */
		case sf::Event::Closed:
			jogo->window.close();
			break;

			/* Mudança entre estados do jogo */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				carregarPause();
			break;


		}
	}
}

void FaseAquatica2::update()
{
	///UPDATE NA VIEW E BACKGROUND
    updateViewEBackground(view);
    ///GERENCIA PONTUAÇÃO
    gerenciarTudo();
    ///EXECUTA
	Lentidades.executar(jogo->deltaTime);
    ///SPAWN DE INIMIGOS
    spawnInimigo -= jogo->deltaTime;
    if(spawnInimigo <= 0)
        gerarInimigos();
	///VERIFICA SE PLAYER ESTÁ VIVO PARA PASSAR PARA O PRÓXIMO FRAME
    checkPlayerVivo();
    ///VERIFICA SE É NECESSÁRIO SALVAR O JOGO
    checkSalvarJogo();
    ///VERIFICA SE O PLAYER GANHOU O JOGO
    checkFimDaFase();
}

void FaseAquatica2::inicializar(const bool player2)
{
	novoJogo(player2);
	gerarObstaculos();
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseAquatica2::carregar(const bool player2)
{
	recuperarJogo(player2);
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseAquatica2::gerarInimigos()
{
    spawnInimigo = 1.5;
    srand(time(NULL));
    int nada = rand();
    int coord = (rand()%300)+100;
    int chance = (rand()%100)+1;

    if((chance >= 55 && chance <= 65 ) || (chance >= 80 && chance <= 88))
        coord *= -1;

    if(chance >= 50 && chance <= 80)
    {
        Inimigo* inimigo = static_cast<Inimigo*> (prototype.MakeEsqueleto(jogo->getPlayer1()->getPosition().x+coord, std::max(coord, 0)));
        Linimigos.incluir(inimigo);
        Lentidades.incluir(static_cast<Entidade*> (inimigo));
    }
    else if(chance > 80)
    {
        Inimigo* inimigo = prototype.MakeTritao(jogo->getPlayer1()->getPosition().x+coord, 0);
        Linimigos.incluir(inimigo);
        Lentidades.incluir(static_cast<Entidade*> (inimigo));
    }

}

void FaseAquatica2::gerarObstaculos()
{
    srand(time(NULL));
    int nObstaculos = (rand()%6)+3;
    int obstaculosGerados = 0;

    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob1 = static_cast<Obstaculo*> (prototype.MakeCaixa(2075, 0));
        Lobstaculos.incluir(ob1);
        Lentidades.incluir(static_cast<Entidade*> (ob1));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob2 = static_cast<Obstaculo*> (prototype.MakeCaixa(975, 0));
        Lobstaculos.incluir(ob2);
        Lentidades.incluir(static_cast<Entidade*> (ob2));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob3 = static_cast<Obstaculo*> (prototype.MakeCaixa(2525, 0));
        Lobstaculos.incluir(ob3);
        Lentidades.incluir(static_cast<Entidade*> (ob3));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob4 = static_cast<Obstaculo*> (prototype.MakeCaixa(2700, 0));
        Lobstaculos.incluir(ob4);
        Lentidades.incluir(static_cast<Entidade*> (ob4));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob5 = static_cast<Obstaculo*> (prototype.MakeCaixa(4650, 0));
        Lobstaculos.incluir(ob5);
        Lentidades.incluir(static_cast<Entidade*> (ob5));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob6 = static_cast<Obstaculo*> (prototype.MakeCaixa(1475, 0));
        Lobstaculos.incluir(ob6);
        Lentidades.incluir(static_cast<Entidade*> (ob6));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob7 = static_cast<Obstaculo*> (prototype.MakeCaixa(4125, 0));
        Lobstaculos.incluir(ob7);
        Lentidades.incluir(static_cast<Entidade*> (ob7));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob8 = static_cast<Obstaculo*> (prototype.MakeCaixa(3750, 0));
        Lobstaculos.incluir(ob8);
        Lentidades.incluir(static_cast<Entidade*> (ob8));
        obstaculosGerados++;
    }
}

void FaseAquatica2::carregarPause()
{
	jogo->pushState(new MenuPause(jogo));
}

void FaseAquatica2::carregarMorte()
{
	jogo->pushState(new MenuMorte(jogo));
}

void FaseAquatica2::carregarProxFase()
{
	jogo->popState();
	jogo->pushState(new FaseNoturna3(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT), jogo, true, jogo->getP2(), gerenciadorDePontuacao.getPontuacao()));
}

void FaseAquatica2::checkFimDaFase()
{
    if (jogo->getPlayer1()->getPosition().x > 6000.0f)
		carregarProxFase();
}

void FaseAquatica2::checkSalvarJogo()
{
    if(jogo->getSalvarFase2())
    {
        jogo->setSalvarFase2(false);
        Lentidades.gravarJogo2();
    }
}

void FaseAquatica2::checkPlayerVivo()
{
    if(!jogo->getPlayer1()->estaVivo())
		carregarMorte();

    if(jogo->getP2())
        if(!jogo->getPlayer2()->estaVivo())
            carregarMorte();
}

void FaseAquatica2::recuperarJogo(const bool player2)
{

    ifstream Recuperador("data/saves/Fase2Gravando.txt", ios::in);
    if ( !Recuperador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    while(!Recuperador.eof())
    {
        int ID;
        float x, y;
        Recuperador >> ID >> x >> y;

        switch(ID)
        {
            case 1:
                Lplataformas.incluir(prototype.MakeChao(x,y));
                break;
            case 2:
                Lplataformas.incluir(prototype.MakePlataforma(x,y));
                break;
            case 3:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakeCaixa(x,y)));
                break;
            case 4:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra(x,y)));
                break;
            case 5:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra2(x,y)));
                break;
            case 6:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeEsqueleto(x,y)));
                break;
            case 7:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeMago(x,y)));
                break;
            case 8:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeTritao(x,y)));
                break;
            case 9:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakeTronco(x,y)));
                break;
            case 10:
                Lprojeteis.incluir(prototype.MakeBolaDeFogo(x,y));
                break;
            case 101:
                jogo->getPlayer1()->getBody()->setPosition(x,y);
                break;
            case 102:
                if(player2)
                    jogo->getPlayer2()->getBody()->setPosition(x,y);///PLAYER2
                break;
        }
    }

    for(int i=0; i < Lobstaculos.getLTObstaculos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lobstaculos.getLTObstaculos()[i])));

    for(int i=0; i < Linimigos.getLTInimigos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Linimigos.getLTInimigos()[i])));

    for(int i=0; i < Lprojeteis.getLTProjeteis().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lprojeteis.getLTProjeteis()[i])));

    for(Platform* aux = Lplataformas.reiniciar(); aux != NULL; aux = Lplataformas.percorrer())
        Lentidades.incluir(static_cast<Entidade*> (aux));

    Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer1()));

    if(player2)
    {
        Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer2()));///PLAYER2
    }

    Recuperador.close();
}

void FaseAquatica2::novoJogo(const bool player2)
{

    ifstream Recuperador("data/saves/Fase2Base.txt", ios::in);
    if ( !Recuperador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    while(!Recuperador.eof())
    {
        int ID;
        float x, y;
        Recuperador >> ID >> x >> y;

        switch(ID)
        {
            case 1:
                Lplataformas.incluir(prototype.MakeChao(x,y));
                break;
            case 2:
                Lplataformas.incluir(prototype.MakePlataforma(x,y));
                break;
            case 3:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakeCaixa(x,y)));
                break;
            case 4:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra(x,y)));
                break;
            case 5:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra2(x,y)));
                break;
            case 6:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeEsqueleto(x,y)));
                break;
            case 7:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeMago(x,y)));
                break;
            case 8:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeTritao(x,y)));
                break;
            case 9:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakeTronco(x,y)));
                break;
            case 10:
                Lprojeteis.incluir(prototype.MakeBolaDeFogo(x,y));
                break;
            case 101:
                jogo->getPlayer1()->getBody()->setPosition(x,y);
                break;
            case 102:
                if(player2)
                    jogo->getPlayer2()->getBody()->setPosition(x,y);///PLAYER2
                break;
        }
    }

    for(int i=0; i < Lobstaculos.getLTObstaculos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lobstaculos.getLTObstaculos()[i])));

    for(int i=0; i < Linimigos.getLTInimigos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Linimigos.getLTInimigos()[i])));

    for(int i=0; i < Lprojeteis.getLTProjeteis().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lprojeteis.getLTProjeteis()[i])));

    for(Platform* aux = Lplataformas.reiniciar(); aux != NULL; aux = Lplataformas.percorrer())
        Lentidades.incluir(static_cast<Entidade*> (aux));

    Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer1()));

    if(player2)
    {
        Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer2()));///PLAYER2
        jogo->getPlayer2()->reiniciar();
    }

    jogo->getPlayer1()->reiniciar();
    Recuperador.close();
}
