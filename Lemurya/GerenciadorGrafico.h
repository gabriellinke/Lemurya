#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

#include <vector>
using std::vector;

class GerenciadorGrafico
{
private:
    vector<sf::Texture> texturePlayer1;
    vector<sf::Vector2u> vecPlayer1;

    vector<sf::Texture> textureEsqueleto;
    vector<sf::Vector2u> vecEsqueleto;

    vector<sf::Texture> textureTritao;
    vector<sf::Vector2u> vecTritao;

    vector<sf::Texture> textureMago;
    vector<sf::Vector2u> vecMago;

    sf::Texture boxTexture;
    sf::Texture stoneTexture1;
    sf::Texture stoneTexture2;
    sf::Texture platTexture;
    sf::Texture chaoTexture;
    sf::Texture fireballTexture;         //POR ENQUANTO SEM ANIMAÇÃO
    sf::Texture logTexture;

    sf::Texture fase1Texture;
    sf::Texture fase2Texture;
    sf::Texture fase3Texture;

    sf::Texture menuPrincipalTexture;
    sf::Texture menuPauseTexture;
    sf::Texture menuMorteTexture;
    sf::Texture logoTexture;

    sf::Font fontBlackCastle;
    sf::Font fontAudiowide;
    sf::Font fontGameOver;

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();
    void inicializar();

    const vector<sf::Texture> getTexturePlayer1() const;
    const vector<sf::Vector2u> getVecPlayer1() const;

    const vector<sf::Texture> getTextureEsqueleto() const;
    const vector<sf::Vector2u> getVecEsqueleto() const;

    const vector<sf::Texture> getTextureTritao() const;
    const vector<sf::Vector2u> getVecTritao() const;

    const vector<sf::Texture> getTextureMago() const;
    const vector<sf::Vector2u> getVecMago() const;

    const sf::Texture getBoxTexture() const;
    const sf::Texture getStoneTexture1() const;
    const sf::Texture getStoneTexture2() const;
    const sf::Texture getPlatTexture() const;
    const sf::Texture getChaoTexture() const;
    const sf::Texture getFireballTexture() const;
    const sf::Texture getLogTexture() const;

    const sf::Texture getFase1Texture() const;
    const sf::Texture getFase2Texture() const;
    const sf::Texture getFase3Texture() const;

    const sf::Texture getMenuPrincipalTexture() const;
    const sf::Texture getMenuPauseTexture() const;
    const sf::Texture getMenuMorteTexture() const;
    const sf::Texture getLogoTexture() const;

    const sf::Font getFontBlackCastle() const;
    const sf::Font getFontAudiowide() const;
    const sf::Font getFontGameOver() const;
};
