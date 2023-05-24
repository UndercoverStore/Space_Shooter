#ifndef SPACE_SHOOTER1_ASTEROID_H
#define SPACE_SHOOTER1_ASTEROID_H
#include "Unit.h"

class Asteroid: public Unit
{
private:
	void initializeAstShape();
public:
    Asteroid(float pos_x, float pos_y);
    virtual ~Asteroid();
    const sf::FloatRect getBounds() const;//primary function calculating rectangle boundings

    void update();
    void render(sf::RenderTarget* target);
    float initializeSpeed();
};

#endif //SPACE_SHOOTER1_ASTEROID_H
