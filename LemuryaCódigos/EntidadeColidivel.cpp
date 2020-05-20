#include "EntidadeColidivel.h"

EntidadeColidivel::EntidadeColidivel():
Entidade()
{
    body = new sf::RectangleShape();
}

void EntidadeColidivel::destruir()
{
    delete body;
}

EntidadeColidivel::~EntidadeColidivel()
{
    destruir();
}

void EntidadeColidivel::setTexture(const sf::Texture pTexture)
{
    texture = pTexture;
    body->setTexture(&texture);
}



void EntidadeColidivel::executar(float deltaTime)
{
}

void EntidadeColidivel::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void EntidadeColidivel::onCollision(const sf::Vector2f direction)
{
    if(direction.x < 0.0f)
        velocity.x = 0.0f;

    else if(direction.x > 0.0f)
        velocity.x = 0.0f;

    if(direction.y < 0.0f)
    {
        velocity.y = 0.0f;
    }

    if(direction.y > 0.0f)
        velocity.y = 0.0f;
}

void EntidadeColidivel::setBody(sf::RectangleShape* b)
{
    body = b;
}

sf::RectangleShape* EntidadeColidivel::getBody() const
{
    return body;
}

int EntidadeColidivel::getVida() const
{
    return 1;
}
