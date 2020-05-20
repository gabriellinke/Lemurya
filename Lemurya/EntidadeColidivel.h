#pragma once
#include "Entidade.h"
#include "Collider.h"

class EntidadeColidivel: public Entidade
{
protected:
    sf::RectangleShape* body;
    sf::Vector2f velocity;
    float speed;

public:
    EntidadeColidivel();
    virtual ~EntidadeColidivel();

    void destruir();

    void setBody(sf::RectangleShape* b);
    sf::RectangleShape* getBody() const;

    void setTexture(const sf::Texture pTexture);

    virtual void onCollision(const sf::Vector2f direction);           //REDEFINIÇÃO PARA O PLAYER
    virtual Collider getCollider() { return Collider(*body); }

    sf::Vector2f getPosition() const { return body->getPosition(); }

    virtual int getVida() const;
    virtual void Draw(sf::RenderWindow& window);    //VIRTUAL PRA DESENHAR OS DOIS BODYS DO PLAYER

    virtual void executar(float deltaTime);
};

