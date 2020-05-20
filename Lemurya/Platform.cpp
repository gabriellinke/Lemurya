#include "Platform.h"

Platform::Platform(sf::Vector2f tam, sf::Vector2f position, sf::Texture textura, int ID):
EntidadeColidivel()
{
    id = ID;
    this->tam = tam;
    body->setSize(tam);
    body->setOrigin(tam/2.0f);
    body->setPosition(position);
    x = position.x;
    y = position.y;

    texture = textura;
    body->setTexture(&texture);
}

Platform::Platform(const Platform& other, float x, float y):
EntidadeColidivel()
{
    id = other.id;
    tam = other.tam;
    body->setSize(tam);
    body->setOrigin(tam/2.0f);
    body->setPosition(sf::Vector2f(x,y));

    this->x = x;
    this->y = y;

    texture = other.texture;
    body->setTexture(&texture);

}

Platform::~Platform()
{
}

void Platform::executar()
{
}

Platform* Platform::clone(const float x, const float y) const
{
    return new Platform(*this, x, y);
}

