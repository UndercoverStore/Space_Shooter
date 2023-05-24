#include "Skin.h"
#include <iostream>

Skin::Skin(float GivX,float GivY) : Unit(sprite, texture) , x(GivX) , y(GivY)//x(Giv)=przypisanie wart. x = GivX
{

    initializeSkin();
    initializeSprite();
    setPosition(  x,  y);
}

Skin::~Skin()
{

}
void Skin::render(sf::RenderTarget& target)
{
    target.draw(sprite);
}

void Skin::initializeSprite()
{
    //Set the texture to the sprite
    sprite.setTexture(texture);

    sprite.scale(1.0f, 1.f);
}
void Skin::initializeSkin()
{
    //Loading text form a file
    if (!texture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space Shooter1\\Textures\\crown2.png"))
    {
        std::cout<< "ERROR::Ship::initializeTexture:: Couldn't load thexture file."<<"\n";
    }
}
void Skin::setPosition(const float x, const float y) {

    sprite.setPosition(x, y);

}
const sf::Vector2f &Skin::getPos() const
{
    return sprite.getPosition();//sprite function which automaticly reads sprite's position
}

float Skin::initializeSpeed() {

}
