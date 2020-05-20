#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
protected:
    int x;
    int y;
    int id;
    sf::Texture texture;
public:
    Entidade();
    virtual ~Entidade();

    void setX(const int X);
    void setY(const int Y);
    void setID(const int ID);
    const int getX() const;
    const int getY() const;
    const int getID() const;

    virtual int getVida() const;
    virtual void destruir() = 0;
    virtual void executar(float deltaTime) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
};

