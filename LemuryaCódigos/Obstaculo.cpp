#include "Obstaculo.h"

Obstaculo::Obstaculo():
EntidadeColidivel()
{
    peso = 0.0;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::executar(float deltaTime)
{
    velocity.x = 0.0f;
    velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

    body->move(velocity * deltaTime);
}

const float Obstaculo::getPeso() const
{
    return peso;
}

