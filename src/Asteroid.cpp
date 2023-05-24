#include "Asteroid.h"
#include <iostream>

Asteroid::Asteroid(float pos_x, float pos_y): Unit(sprite, texture)
{
    initializeAstShape();
    initializeSpeed();
    sprite.setPosition( pos_x,  pos_y);
}
Asteroid::~Asteroid()
{

}

//Functions
void Asteroid::initializeAstShape()
{
    //Loading text form a file
    if (!texture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space Shooter1\\Textures\\Asteroid2.png"))
    {
        std::cout<< "ERROR,Ship,initializeAstShape: Couldn't load thexture file."<<"\n";
    }
    sprite.setTexture(texture);

    //Resize sprite
    //sprite.scale(1.f, 1.f);
}

void Asteroid::render(sf::RenderTarget* target)
{
    target->draw(sprite);
}

const sf::FloatRect Asteroid::getBounds() const//rectangle boundings of the vertex array
{
    return sprite.getGlobalBounds();
}

void Asteroid::update() {
    sprite.move(0.f,movementSpeed);
}

float Asteroid::initializeSpeed() {
    movementSpeed =  2.f;
    return movementSpeed;
}
