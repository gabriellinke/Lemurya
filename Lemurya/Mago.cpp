#include "Mago.h"
#include "Fase.h"

void Mago::inicializa(const vector<sf::Texture> textureMago, const vector<sf::Vector2u> vecMago, const sf::Vector2f posicao, Fase* pFase,const int ID)
{
    fase = pFase;
    id = ID;
    coolDownAtack = 0;
    coolDownSpawn = 0;
    atacking = false;
    spawning = false;
    atack = false;
    spawn = false;

    this->vecTexture = textureMago;
    this->vecVector  = vecMago;

    speed = 50.0f;
    body->setSize(sf::Vector2f(120.f, 160.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(posicao);

    x = posicao.x;
    y = posicao.y;

    setTexture(vecTexture[0]);

    animacao.push_back(new Animation(&vecTexture[0], vecVector[0], 0.3f));  //PARADO
    animacao.push_back(new Animation(&vecTexture[1], vecVector[1], 0.3f));  //ANDANDO
    animacao.push_back(new Animation(&vecTexture[2], vecVector[2], 0.15f));  //ATACANDO
    animacao.push_back(new Animation(&vecTexture[3], vecVector[3], 0.15f));  //SPAWNANDO

}

Mago::Mago(const Mago& other, float x, float y)
{
    inicializa(other.vecTexture, other.vecVector, sf::Vector2f(x,y), other.fase, other.id);
}

Mago::Mago(const vector<sf::Texture> textureMago, const vector<sf::Vector2u> vecMago, const sf::Vector2f posicao, Fase* pFase, const int ID):
Inimigo()
{
    inicializa(textureMago, vecMago, posicao, pFase, ID);
}

Mago::~Mago()
{
    for(int i=0; i<4; i++)
        delete animacao[i];
}

void Mago::executar(float deltaTime)
{
    coolDownAtack -= deltaTime;
    coolDownSpawn -= deltaTime;
    row = 0;
    velocity.x = 0.0f;

    if(spawning)
    {
        coolDownSpawn = 10;
        if(spawn)
        {
            spawn = false;
            fase->spawnarEsqueleto(x,0);
        }

        row = 3;
        body->setTexture(&vecTexture[row]);
        body->setTextureRect(animacao[row]->uvRect);
        animacao[row]->Update(deltaTime, faceRight, spawning);
    }

    else if(atacking)
    {
        coolDownAtack = 5;
        if(atack)
        {
            atack = false;
            fase->lancarBolaDeFogo(x,y);
        }

        row = 2;
        body->setTexture(&vecTexture[row]);
        body->setTextureRect(animacao[row]->uvRect);
        animacao[row]->Update(deltaTime, faceRight, atacking);
    }

    else
    {
        if(fase->getPlayer1() != NULL)
        {
            if(fase->getPlayer1()->getPosition().x > body->getPosition().x)
            {
                row = 0;
                body->setTexture(&vecTexture[row]);
                faceRight = true;
            }
            else
            {
                row = 0;
                body->setTexture(&vecTexture[row]);
                faceRight = false;
            }

            atack = true;
            atacking = false;
            spawn = true;
            spawning = false;

            if(abs(fase->getPlayer1()->getPosition().x - x) < 500 && coolDownSpawn <= 0 && fase->getNInimigos() < 15)
                spawning = true;
            if(coolDownAtack <= 0 && !spawning)
                atacking = true;

            animacao[row]->Update(deltaTime, faceRight);
            body->setTextureRect(animacao[row]->uvRect);
        }
    }

        velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

        body->move(velocity * deltaTime);

        x = this->getPosition().x;
        y = this->getPosition().y;
}

Mago* Mago::clone(const float x, const float y) const
{
    return new Mago(*this, x, y);
}

