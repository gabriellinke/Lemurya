#include "Pedra.h"

Pedra::Pedra(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso, const int ID):
Obstaculo()
{
    inicializa(tam, position, text, peso, ID);
}

void Pedra::inicializa(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso, const int ID)
{
    this->tam = tam;
    id = ID;
    body->setSize(tam);
    body->setOrigin(tam/2.0f);
    body->setPosition(position);

    x = position.x;
    y = position.y;

    this->peso = peso;

    texture = text;
    body->setTexture(&texture);
}
Pedra::~Pedra()
{
}

Pedra::Pedra(const Pedra& other, float x, float y):
Obstaculo()
{
    inicializa(other.tam, sf::Vector2f(x,y), other.texture, other.peso, other.id);
}

void Pedra::executar(float deltaTime)
{
    velocity.x = 0.0f;
    velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

    body->move(velocity * deltaTime);

    x = this->getPosition().x;
    y = this->getPosition().y;
}

Pedra* Pedra::clone(const float x, const float y) const
{
    return new Pedra(*this, x, y);
}

