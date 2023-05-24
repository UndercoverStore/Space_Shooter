#ifndef SPACE_SHOOTER1_SKIN_H
#define SPACE_SHOOTER1_SKIN_H
#include "Unit.h"


class Skin : public Unit
{
private:
    void initializeSkin();
    const float x;
    const float y;
public:
    Skin(float ,float);
    ~Skin();
    void render(sf::RenderTarget& target);
    const sf::Vector2f& getPos() const;

    void initializeSprite();
    void setPosition(const float , const float );
    float initializeSpeed();

};


#endif //SPACE_SHOOTER1_SKIN_H
