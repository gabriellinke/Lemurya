#include "FaseNoturna3.h"
#include "Lemurya.h"
#include "MenuMorte.h"
#include "MenuPause.h"

FaseNoturna3::FaseNoturna3(const sf::Vector2f tam, Lemurya* jogo, const bool newGame, const bool player2, const int pont):
Fase(tam, jogo)
{
	texture = jogo->getGerenciadorGrafico().getFase3Texture();
    body->setTexture(&texture);
    spawnInimigo = 2;

    boss = prototype.MakeMago(1000, -200);
    Linimigos.incluir(static_cast<Inimigo*>(boss));
    Lentidades.incluir(static_cast<Entidade*>(boss));

    jogo->setSalvarFase3(false);

    if(newGame)
        inicializar(player2);
    else
        carregar(player2);

    jogo->getPlayer1()->setRanking(pont);
}

FaseNoturna3::~FaseNoturna3()
{
}
void FaseNoturna3::draw()
{
	jogo->window.draw(*body);
	gerenciadorDePontuacao.draw();
	Lentidades.Draw(jogo->window);
}

void FaseNoturna3::input()
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

void FaseNoturna3::update()
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
    checkFimDeJogo();
}

void FaseNoturna3::inicializar(const bool player2)
{
	novoJogo(player2);
	jogo->getPlayer1()->reiniciar();
	gerarObstaculos();
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseNoturna3::carregar(const bool player2)
{
	recuperarJogo(player2);
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseNoturna3::gerarInimigos()
{
    spawnInimigo = 1.5;
    srand(time(NULL));
    int nada = rand();
    int coord = (rand()%300)+100;
    int chance = (rand()%100)+1;

    if(chance >= 50 && chance <= 68 )
        coord *= -1;

    if(chance >= 50)
    {
        Inimigo* inimigo = static_cast<Inimigo*> (prototype.MakeEsqueleto(jogo->getPlayer1()->getPosition().x+coord, std::max(coord, 0)));
        Linimigos.incluir(inimigo);
        Lentidades.incluir(static_cast<Entidade*> (inimigo));
    }


}

void FaseNoturna3::gerarObstaculos()
{
    srand(time(NULL));
    int n = (rand()%2)+1;

    if(n == 1)
    {
        Obstaculo* ob1 = static_cast<Obstaculo*> (prototype.MakeCaixa(-255, 0));
        Lobstaculos.incluir(ob1);
        Lentidades.incluir(static_cast<Entidade*> (ob1));
    }
    if(n == 2)
    {
        Obstaculo* ob2 = static_cast<Obstaculo*> (prototype.MakeCaixa(1690, 0));
        Lobstaculos.incluir(ob2);
        Lentidades.incluir(static_cast<Entidade*> (ob2));
    }

}

void FaseNoturna3::carregarPause()
{
	jogo->pushState(new MenuPause(jogo));
}

void FaseNoturna3::carregarMorte()
{
	jogo->pushState(new MenuMorte(jogo));
}

void FaseNoturna3::carregarProxFase()
{
    carregarMorte();
}

void FaseNoturna3::checkFimDeJogo()
{
    if(!boss->getVida())
    {
        jogo->setGanharJogo(true);
        jogo->getPlayer1()->setRanking(jogo->getPlayer1()->getRanking()+500);
        carregarProxFase();
    }
}

void FaseNoturna3::checkSalvarJogo()
{
    if(jogo->getSalvarFase3())
    {
        jogo->setSalvarFase3(false);
        Lentidades.gravarJogo3();
    }
}

void FaseNoturna3::checkPlayerVivo()
{
    if(!jogo->getPlayer1()->estaVivo())
		carregarMorte();

    if(jogo->getP2())
        if(!jogo->getPlayer2()->estaVivo())
            carregarMorte();
}

void FaseNoturna3::recuperarJogo(const bool player2)
{

    ifstream Recuperador("data/saves/Fase3Gravando.txt", ios::in);
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

void FaseNoturna3::novoJogo(const bool player2)
{

    ifstream Recuperador("data/saves/Fase3Base.txt", ios::in);
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
