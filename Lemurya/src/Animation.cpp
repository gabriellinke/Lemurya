#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime  = switchTime;

    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / (float)imageCount.x;
    uvRect.height = texture->getSize().y / (float)imageCount.y;

}

Animation::~Animation()
{
    //dtor
}

void Animation::Update(float deltaTime, bool faceRight)
{
    currentImage.y  = 0;
    totalTime += deltaTime;

    if(totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if(currentImage.x >= imageCount.x)
            currentImage.x = 0;
    }

    uvRect.top  = currentImage.y * uvRect.height;

    if(faceRight)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}

///TESTES PARA O ATAQUE
void Animation::Update(float deltaTime, bool faceRight, bool& notEnd)
{
    currentImage.y  = 0;
    totalTime += deltaTime;

    if(totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if(currentImage.x >= imageCount.x)
        {
            notEnd = false;
            currentImage.x = 0;
        }

    }

    uvRect.top  = currentImage.y * uvRect.height;

    if(faceRight)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}


int Animation::getCurrentImage()
{
    return (int)currentImage.x;
}
