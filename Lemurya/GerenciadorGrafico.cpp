#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico()
{
    inicializar();
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::inicializar()
{
    sf::RenderWindow window(sf::VideoMode(0.0f, 0.0f), "Lemurya");      ///CRIADO PARA EVITAR WARNINGS AO INICIAR O JOGO
    ///Necessita de janela pra textura carregar


    ///REPTILIANO REI
    sf::Texture p1Parado;
    sf::Texture p1Andando;
    sf::Texture p1Pulando;
    sf::Texture p1Atacando;
    sf::Texture p1Morrendo;
    sf::Texture iconeVida;
    ///ESQUELETO
    sf::Texture esqueletoParado;
    sf::Texture esqueletoAndando;
    sf::Texture esqueletoAtacando;
    ///TRITÃO
    sf::Texture tritaoParado;
    ///MAGO
    sf::Texture magoParado;
    sf::Texture magoAndando;
    sf::Texture magoAtacando;
    sf::Texture magoSpawnando;

    try
    {
        ///FONTES
        if(!fontBlackCastle.loadFromFile("data/fonts/BlackCastleMF.ttf"))
            throw 1;
        if (!fontAudiowide.loadFromFile("data/fonts/Audiowide.ttf"))
            throw 1;
        if (!fontGameOver.loadFromFile("data/fonts/game_over.ttf"))
            throw 1;

        ///TEXTURAS MENU
    	if (!menuPrincipalTexture.loadFromFile("data/sprites/Menu.jpg"))
            throw 2;
        if (!menuPauseTexture.loadFromFile("data/sprites/Pause.jpg"))
            throw 2;
        if (!menuMorteTexture.loadFromFile("data/sprites/FundoGameOver.png"))
            throw 2;
        if (!logoTexture.loadFromFile("data/sprites/LemuryaIcon.jpg"))
            throw 2;

        ///TEXTURAS DAS FASES
        if(!fase1Texture.loadFromFile("data/sprites/Fase1.png"))
            throw 3;
        if(!fase2Texture.loadFromFile("data/sprites/Fase2.png"))
            throw 3;
        if(!fase3Texture.loadFromFile("data/sprites/Fase3.png"))
            throw 3;

        ///TEXTURAS PLAYER
        if(!p1Parado.loadFromFile("data/sprites/Parado.png"))
            throw 4;
        if(!p1Andando.loadFromFile("data/sprites/Andando.png"))
            throw 4;
        if(!p1Pulando.loadFromFile("data/sprites/Pulando.png"))
            throw 4;
        if(!p1Atacando.loadFromFile("data/sprites/Atacando.png"))
            throw 4;
        if(!p1Morrendo.loadFromFile("data/sprites/Morrendo.png"))
            throw 4;
        if(!iconeVida.loadFromFile("data/sprites/LemuryaIcon.png"))
            throw 4;

        ///ESQUELETO
        if(!esqueletoParado.loadFromFile("data/sprites/EsqueletoParado.png"))
            throw 5;
        if(!esqueletoAndando.loadFromFile("data/sprites/EsqueletoAndando.png"))
            throw 5;
        if(!esqueletoAtacando.loadFromFile("data/sprites/EsqueletoAtacando1.png"))
            throw 5;

        ///TRITÃO
        if(!tritaoParado.loadFromFile("data/sprites/TritaoTeste.png"))
            throw 6;

        ///MAGO
        if(!magoParado.loadFromFile("data/sprites/MagoTeste.png"))
            throw 7;
        if(!magoAndando.loadFromFile("data/sprites/magoAndando.png"))
            throw 7;
        if(!magoAtacando.loadFromFile("data/sprites/magoAtacando.png"))
            throw 7;
        if(!magoSpawnando.loadFromFile("data/sprites/magoSpawnando.png"))
            throw 7;
        if(!fireballTexture.loadFromFile("data/sprites/BolaDeFogo.png"))
            throw 7;

        ///OBSTÁCULOS
        if(!boxTexture.loadFromFile("data/sprites/Caixa.png"))
            throw 8;
        if(!stoneTexture1.loadFromFile("data/sprites/Pedra1.png"))
            throw 8;
        if(!stoneTexture2.loadFromFile("data/sprites/Pedra2.png"))
            throw 8;
        if(!platTexture.loadFromFile("data/sprites/BGplat.png"))
            throw 8;
        if(!chaoTexture.loadFromFile("data/sprites/Chao.png"))
            throw 8;
        if(!logTexture.loadFromFile("data/sprites/Tronco.png"))
            throw 8;

    }
    catch(int i)
    {
        if(i == 1)
            std::cout << "Erro ao carregar Fontes" << std::endl;
        if(i == 2)
            std::cout << "Erro ao carregar as texturas do Menu" << std::endl;
        if(i == 3)
            std::cout << "Erro ao carregar a texturas das Fases" << std::endl;
        if(i == 4)
            std::cout << "Erro ao carregar a textura do jogador" << std::endl;
        if(i == 5)
            std::cout << "Erro ao carregar a textura do esqueleto" << std::endl;
        if(i == 6)
            std::cout << "Erro ao carregar a textura do tritao" << std::endl;
        if(i == 7)
            std::cout << "Erro ao carregar a textura do mago" << std::endl;
        if(i == 8)
            std::cout << "Erro ao carregar as texturas dos obstaculos" << std::endl;

        exit(1);
    }


    ///REPTILIANO REI
    texturePlayer1.push_back(p1Parado);
    vecPlayer1.push_back(sf::Vector2u(2,1));

    texturePlayer1.push_back(p1Andando);
    vecPlayer1.push_back(sf::Vector2u(6,1));

    texturePlayer1.push_back(p1Pulando);
    vecPlayer1.push_back(sf::Vector2u(5,1));

    texturePlayer1.push_back(p1Atacando);
    vecPlayer1.push_back(sf::Vector2u(4,1));

    texturePlayer1.push_back(p1Morrendo);
    vecPlayer1.push_back(sf::Vector2u(4,1));

    texturePlayer1.push_back(iconeVida);

    ///ESQUELETO
    textureEsqueleto.push_back(esqueletoParado);
    vecEsqueleto.push_back(sf::Vector2u(2,1));

    textureEsqueleto.push_back(esqueletoAndando);
    vecEsqueleto.push_back(sf::Vector2u(6,1));

    textureEsqueleto.push_back(esqueletoAtacando);
    vecEsqueleto.push_back(sf::Vector2u(5,1));

    ///TRITÃO
    textureTritao.push_back(tritaoParado);
    vecTritao.push_back(sf::Vector2u(1,1));

    ///MAGO
    textureMago.push_back(magoParado);
    vecMago.push_back(sf::Vector2u(1,1));

    textureMago.push_back(magoAndando);
    vecMago.push_back(sf::Vector2u(4,1));

    textureMago.push_back(magoAtacando);
    vecMago.push_back(sf::Vector2u(3,1));

    textureMago.push_back(magoSpawnando);
    vecMago.push_back(sf::Vector2u(7,1));

}

const vector<sf::Texture> GerenciadorGrafico::getTexturePlayer1() const
{
    return texturePlayer1;
}

const vector<sf::Vector2u> GerenciadorGrafico::getVecPlayer1() const
{
    return vecPlayer1;
}

const vector<sf::Texture> GerenciadorGrafico::getTextureEsqueleto() const
{
    return textureEsqueleto;
}

const vector<sf::Vector2u> GerenciadorGrafico::getVecEsqueleto() const
{
    return vecEsqueleto;
}

const vector<sf::Texture> GerenciadorGrafico::getTextureTritao() const
{
    return textureTritao;
}

const vector<sf::Vector2u> GerenciadorGrafico::getVecTritao() const
{
    return vecTritao;
}

const vector<sf::Texture> GerenciadorGrafico::getTextureMago() const
{
    return textureMago;
}

const vector<sf::Vector2u> GerenciadorGrafico::getVecMago() const
{
    return vecMago;
}

const sf::Texture GerenciadorGrafico::getBoxTexture() const
{
    return boxTexture;
}

const sf::Texture GerenciadorGrafico::getStoneTexture1() const
{
    return stoneTexture1;
}

const sf::Texture GerenciadorGrafico::getStoneTexture2() const
{
    return stoneTexture2;
}

const sf::Texture GerenciadorGrafico::getPlatTexture() const
{
    return platTexture;
}

const sf::Texture GerenciadorGrafico::getChaoTexture() const
{
    return chaoTexture;
}

const sf::Texture GerenciadorGrafico::getFireballTexture() const
{
    return fireballTexture;
}

const sf::Texture GerenciadorGrafico::getFase1Texture() const
{
    return fase1Texture;
}

const sf::Texture GerenciadorGrafico::getFase2Texture() const
{
    return fase2Texture;
}

const sf::Texture GerenciadorGrafico::getFase3Texture() const
{
    return fase3Texture;
}

const sf::Font GerenciadorGrafico::getFontBlackCastle() const
{
    return fontBlackCastle;
}

const sf::Font GerenciadorGrafico::getFontAudiowide() const
{
    return fontAudiowide;
}

const sf::Font GerenciadorGrafico::getFontGameOver() const
{
    return fontGameOver;
}

const sf::Texture GerenciadorGrafico::getMenuPauseTexture() const
{
    return menuPauseTexture;
}

const sf::Texture GerenciadorGrafico::getMenuMorteTexture() const
{
    return menuMorteTexture;
}

const sf::Texture GerenciadorGrafico::getMenuPrincipalTexture() const
{
    return menuPrincipalTexture;
}

const sf::Texture GerenciadorGrafico::getLogoTexture() const
{
    return logoTexture;
}

const sf::Texture GerenciadorGrafico::getLogTexture() const
{
    return logTexture;
}
