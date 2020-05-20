#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;

class Animation
{
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    virtual ~Animation();

    sf::IntRect uvRect;

    void Update(float deltaTime, bool faceRight);
    void Update(float deltaTime, bool faceRight, bool& notEnd);
    int getCurrentImage();


private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};

