#ifndef SPACE_SHOOTER1_BULLET_H
#define SPACE_SHOOTER1_BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float movementSpeed;
public:
    Bullet(sf::Texture* texture,float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed);
    virtual ~Bullet();

    const sf::FloatRect getBounds() const;//primary function calculating rectangle boundings

    //Functions
    void update();
    void render(sf::RenderTarget* target);
};

#endif //SPACE_SHOOTER1_BULLET_H
