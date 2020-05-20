#include "Esqueleto.h"
#include "Fase.h"

void Esqueleto::inicializa(const vector<sf::Texture> textureEsqueleto, const vector<sf::Vector2u> vecEsqueleto, const sf::Vector2f posicao, Fase* pFase, const int ID)
{
    fase = pFase;
    id = ID;

    this->vecTexture = textureEsqueleto;
    this->vecVector  = vecEsqueleto;

    speed = 50.0f;
    body->setSize(sf::Vector2f(80.f, 120.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(posicao);

    x = posicao.x;
    y = posicao.y;

    setTexture(vecTexture[0]);

    animacao.push_back(new Animation(&vecTexture[0], vecVector[0], 0.2f));
    animacao.push_back(new Animation(&vecTexture[1], vecVector[1], 0.2f));
    animacao.push_back(new Animation(&vecTexture[2], vecVector[2], 0.2f));

}

Esqueleto::Esqueleto(const vector<sf::Texture> textureEsqueleto, const vector<sf::Vector2u> vecEsqueleto, const sf::Vector2f posicao, Fase* pFase, const int ID):
Inimigo()
{
    inicializa(textureEsqueleto, vecEsqueleto, posicao, pFase, ID);
}

Esqueleto::Esqueleto(const Esqueleto& other, float x, float y)
{
   inicializa(other.vecTexture, other.vecVector, sf::Vector2f(x,y), other.fase, other.id);
}


Esqueleto::~Esqueleto()
{
    for(int i=0; i<3; i++)
        delete animacao[i];
}

void Esqueleto::executar(float deltaTime)
{
    row = 0;
    velocity.x = 0.0f;
    if(fase->getPlayer1() != NULL)
    {
        if(fase->getPlayer1()->getPosition().x > body->getPosition().x)
        {
            row = 1;
            body->setTexture(&vecTexture[row]);
            faceRight = true;
            if((fase->getPlayer1()->getPosition().x - body->getPosition().x) < 1000)
                velocity.x += speed;
        }
        else if(fase->getPlayer1()->getPosition().x < body->getPosition().x)
        {
            row = 1;
            body->setTexture(&vecTexture[row]);
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

Esqueleto* Esqueleto::clone(const float x, const float y) const
{
    return new Esqueleto(*this, x, y);
}

