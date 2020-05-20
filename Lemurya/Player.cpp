#include "Player.h"

Player::Player():
Personagem()
{
    id        = 101;
    row       = 0;
    faceRight = true;
    canJump   = false;
    ranking   = 0;
    vida      = 10;
}

void Player::reiniciar()
{
    damage->setSize(sf::Vector2f(0,50.0f));
    damage->setPosition(200, -300);
    vida = 10;
    ranking = 0;
}


void Player::inicializa(const float speed, const float jumpHeight, vector<sf::Texture> playerTexture, vector<sf::Vector2u> playerVector, float switchTime, const bool p2)
{
    player2 = p2;
    if(player2)
        id    = 102;
    else
        id    = 101;


    row       = 0;
    faceRight = true;
    canJump   = false;
    ranking   = 0;
    vida      = 10;

    this->speed      = speed;
    this->jumpHeight = jumpHeight;
    this->vecTexture = playerTexture;
    this->vecVector  = playerVector;

    body->setSize(sf::Vector2f(100.f, 150.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(50.0f, 500.0f);
    if(player2)
        body->setFillColor(sf::Color(6,59,255));
    else
        body->setFillColor(sf::Color::White);

    atackBody = new sf::RectangleShape();

    atackBody->setSize(sf::Vector2f(40.f, 150.0f));
    atackBody->setOrigin(atackBody->getSize() / 2.0f);
    atackBody->setPosition(50.0f, 500.0f);
    atackBody->setFillColor(sf::Color::Transparent);

    animationBody = new sf::RectangleShape();

    animationBody->setSize(sf::Vector2f(150.f, 150.0f));
    animationBody->setOrigin(atackBody->getSize() / 2.0f);
    animationBody->setPosition(50.0f, 500.0f);
    animationBody->setFillColor(sf::Color::Transparent);

    life     = new sf::RectangleShape();
    damage   = new sf::RectangleShape();
    life->setFillColor(sf::Color::Green);
    damage->setFillColor(sf::Color::Red);
    life->setSize(sf::Vector2f(200.0f, 50.0f));
    damage->setSize(sf::Vector2f(0.0f, 50.0f));
    life->setPosition(100, -300);
    damage->setPosition(200, -300);

    lifeIcon = new sf::RectangleShape();
    lifeIcon->setSize(sf::Vector2f(75.0, 110.0));
    lifeIcon->setFillColor(sf::Color::White);
    lifeIcon->setPosition(30, -300);
    lifeIcon->setTexture(&vecTexture[5]);

    setTexture(vecTexture[0]);

    animacao.push_back(new Animation(&playerTexture[0], playerVector[0], switchTime));
    animacao.push_back(new Animation(&playerTexture[1], playerVector[1], switchTime));
    animacao.push_back(new Animation(&playerTexture[2], playerVector[2], switchTime));
    animacao.push_back(new Animation(&playerTexture[3], playerVector[3], 0.15));
    animacao.push_back(new Animation(&playerTexture[4], playerVector[4], switchTime));
}

Player::Player(const float speed, const float jumpHeight, vector<sf::Texture> playerTexture, vector<sf::Vector2u> playerVector, float switchTime, const bool p2):
Personagem()
{
    inicializa(speed, jumpHeight, playerTexture, playerVector, switchTime, p2);
}

Player::~Player()
{
    delete animationBody;
    delete atackBody;

    for(int i=0; i<5; i++)
        delete animacao[i];
}

void Player::onCollision(const sf::Vector2f direction)
{
    if(direction.x < 0.0f)
        velocity.x = 0.0f;

    else if(direction.x > 0.0f)
        velocity.x = 0.0f;

    if(direction.y < 0.0f)
    {
        velocity.y = 0.0f;
        canJump = true;
    }

    if(direction.y > 0.0f)
        velocity.y = 0.0f;
}

void Player::Update(float deltaTime)
{

    velocity.x = 0.0f;
    velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

    if(!player2)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))         //ANDANDO
            velocity.x -= speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            velocity.x += speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)      //PULANDO
                velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);


        if(!atacking)
        {
           if(velocity.y < -200.0f)
            {
                atacking = false;
                row = 2;                                //ANIMACÃO PULANDO
                body->setTexture(&vecTexture[row]);

            }

            else if(velocity.x == 0.0f)
            {
                atacking = false;
                row = 0;                                    //SELECIONA COLUNA DE ANIMAÇÃO EM QUE ESTÁ PARADO
                body->setTexture(&vecTexture[row]);
            }

            else
            {
                atacking = false;
                row = 1;                                      //ANIMAÇÃO SE MOVENDO
                body->setTexture(&vecTexture[row]);

                if(velocity.x > 0.0f)
                    faceRight = true;       //MOVENDO PARA A DIREITA
                else
                    faceRight = false;      //MOVENDO PARA A ESQUERDA
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))     //ATACANDO
            {
                atacking = true;
                row = 3;
                animationBody->setTexture(&vecTexture[row]);
                if(velocity.x > 0)
                    velocity.x -= speed/3;
                else if(velocity.x < 0)
                    velocity.x += speed/3;

            }

                body->setFillColor(sf::Color::White);
                animationBody->setFillColor(sf::Color::Transparent);
                animacao[row]->Update(deltaTime, faceRight, atacking);
                body->setTextureRect(animacao[row]->uvRect);
        }
        else
        {
                x = atackBody->getPosition().x;
                y = atackBody->getPosition().y;

                if(faceRight)
                    body->setPosition(x-70, y);
                else
                    body->setPosition(x+70, y);

                body->setFillColor(sf::Color::Transparent);
                animationBody->setFillColor(sf::Color::White);
                animationBody->setTextureRect(animacao[row]->uvRect);
                animacao[row]->Update(deltaTime, faceRight, atacking);

        }

            body->move(velocity * deltaTime);
            canJump = false;

            x = body->getPosition().x;
            y = body->getPosition().y;

            if(faceRight)
            {
                animationBody->setPosition(x-30,y);
                atackBody->setPosition(x+70,y);
            }

            else
            {
                atackBody->setPosition(x-70,y);
                animationBody->setPosition(x-80,y);
            }
    }

    else        ///PLAYER2
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))         //ANDANDO
            velocity.x -= speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocity.x += speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)      //PULANDO
                velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);


        if(!atacking)
        {
           if(velocity.y < -200.0f)
            {
                atacking = false;
                row = 2;                                //ANIMACÃO PULANDO
                body->setTexture(&vecTexture[row]);

            }

            else if(velocity.x == 0.0f)
            {
                atacking = false;
                row = 0;                                    //SELECIONA COLUNA DE ANIMAÇÃO EM QUE ESTÁ PARADO
                body->setTexture(&vecTexture[row]);
            }

            else
            {
                atacking = false;
                row = 1;                                      //ANIMAÇÃO SE MOVENDO
                body->setTexture(&vecTexture[row]);

                if(velocity.x > 0.0f)
                    faceRight = true;       //MOVENDO PARA A DIREITA
                else
                    faceRight = false;      //MOVENDO PARA A ESQUERDA
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))     //ATACANDO
            {
                atacking = true;
                row = 3;
                animationBody->setTexture(&vecTexture[row]);
                if(velocity.x > 0)
                    velocity.x -= speed/3;
                else if(velocity.x < 0)
                    velocity.x += speed/3;

            }

                body->setFillColor(sf::Color(6,59,255));
                animationBody->setFillColor(sf::Color::Transparent);
                animacao[row]->Update(deltaTime, faceRight, atacking);
                body->setTextureRect(animacao[row]->uvRect);
        }
        else
        {
                x = atackBody->getPosition().x;
                y = atackBody->getPosition().y;

                if(faceRight)
                    body->setPosition(x-70, y);
                else
                    body->setPosition(x+70, y);

                body->setFillColor(sf::Color::Transparent);
                animationBody->setFillColor(sf::Color(6,59,255));
                animationBody->setTextureRect(animacao[row]->uvRect);
                animacao[row]->Update(deltaTime, faceRight, atacking);

        }

            body->move(velocity * deltaTime);
            canJump = false;

            x = body->getPosition().x;
            y = body->getPosition().y;

            if(faceRight)
            {
                animationBody->setPosition(x-30,y);
                atackBody->setPosition(x+70,y);
            }

            else
            {
                atackBody->setPosition(x-70,y);
                animationBody->setPosition(x-80,y);
            }
    }

}

void Player::executar(float deltaTime)
{
    this->Update(deltaTime);
}

void Player::knockback(const sf::Vector2f direction)
{
    if(direction.x < 0.0f)              //PERSONAGEM ESTÁ NA ESQUERDA
    {
        body->move(-30.0f,0);
    }

    else if(direction.x > 0.0f)         //PERSONAGEM ESTÁ NA DIREITA
    {
        body->move(30.0f,0);
    }

    if(direction.y < 0.0f)
    {
        velocity.y -= speed * 5.0f;
        canJump = true;
    }

    if(direction.y > 0.0f)
        velocity.y = 0.0f;

}

const bool Player::estaVivo() const
{
    return ((vida>0) && (body->getPosition().y < 810));
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(*atackBody);
    window.draw(*body);
    window.draw(*animationBody);
    window.draw(*life);
    window.draw(*damage);
    window.draw(*lifeIcon);
}

Collider Player::getCollider() const
{
    if(atacking)
        return Collider(*atackBody);
    else
        return Collider(*body);
}

const bool Player::isAtacking() const
{
    return atacking;
}

const int Player::getRanking() const
{
    return ranking;
}

void Player::setRanking(const int r)
{
    ranking = r;
}

sf::RectangleShape* Player::getDamage() const
{
    return damage;
}

sf::RectangleShape* Player::getLife() const
{
    return life;
}

sf::RectangleShape* Player::getLifeIcon() const
{
    return lifeIcon;
}
