#ifndef SPACE_SHOOTER1_UNIT_H
#define SPACE_SHOOTER1_UNIT_H
#include <SFML/Graphics.hpp>


class Unit
{
private:

public:
    sf::Sprite sprite; //incons //public to give Ship acces to it.
    sf::Texture texture;
    float movementSpeed;

    Unit(sf::Sprite sprite,sf::Texture texture);
    virtual ~Unit();

    //Functions
    virtual float initializeSpeed()=0;//entirely vitual function
};


#endif //SPACE_SHOOTER1_UNIT_H
