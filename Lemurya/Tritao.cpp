#include "Tritao.h"
#include "Fase.h"

void Tritao::inicializa(const vector<sf::Texture> textureTritao, const vector<sf::Vector2u> vecTritao, const sf::Vector2f posicao, Fase* pFase, const int ID)
{
    fase = pFase;
    id = ID;

    this->vecTexture = textureTritao;
    this->vecVector  = vecTritao;

    speed = 35.0f;
    body->setSize(sf::Vector2f(80.f, 120.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(posicao);

    x = posicao.x;
    y = posicao.y;

    setTexture(vecTexture[0]);

    animacao.push_back(new Animation(&vecTexture[0], vecVector[0], 0.2f));
}

Tritao::Tritao(const Tritao& other, float x, float y)
{
    inicializa(other.vecTexture, other.vecVector, sf::Vector2f(x,y), other.fase, other.id);
}

Tritao::Tritao(vector<sf::Texture> textureTritao, vector<sf::Vector2u> vecTritao, sf::Vector2f posicao, Fase* pFase, int ID):
Inimigo()
{
    inicializa(textureTritao, vecTritao, posicao, pFase, ID);
}

Tritao::~Tritao()
{
    for(int i=0; i<1; i++)
        delete animacao[i];
}

void Tritao::executar(float deltaTime)
{
    row = 0;
    velocity.x = 0.0f;
    if(fase->getPlayer1() != NULL)
    {
            if(fase->getPlayer1()->getPosition().x > body->getPosition().x)
        {
            faceRight = true;
            if((fase->getPlayer1()->getPosition().x - body->getPosition().x) < 1000)
                velocity.x += speed;
        }
        else
        {
            faceRight = false;
            if((body->getPosition().x - fase->getPlayer1()->getPosition().x) < 1000)
                velocity.x -= speed;
        }

        velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

        animacao[row]->Update(deltaTime, faceRight);
        body->setTextureRect(animacao[row]->uvRect);
        body->move(velocity * deltaTime);

        x = this->getPosition().x;
        y = this->getPosition().y;
    }
}

Tritao* Tritao::clone(const float x, const float y) const
{
    return new Tritao(*this, x, y);
}

