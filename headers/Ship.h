#ifndef SPACE_SHOOTER1_SHIP_H
#define SPACE_SHOOTER1_SHIP_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Unit.h"
#include "Skin.h"

class Ship: public Unit
{
private:


    float attackCooldown;
    float attackCooldownMax;

    const float x=350;
    const float y=520;
    float XX;
    float YY;

    //Private functions
    void inializeVariables();
    void initializeTexture();
    void initializeSprite();
public:
    Ship();
    virtual ~Ship();
    Skin skin;
    //Accesor
    const sf::Vector2f& getPos() const;
    sf::FloatRect getBounds();

    //Functions
    void move(const float dirX, const float dirY);
    const bool canAttack();

    void attack();
    void render(sf::RenderTarget& target);
    void setPosition(const float x, const float y);

    float initializeSpeed();
};


#endif //SPACE_SHOOTER1_SHIP_H
