#include "Ship.h"
#include "Unit.h"

//Constractor/Destructor
Ship::Ship():Unit(sprite, texture) , skin(x,y)
{
    inializeVariables();
    initializeTexture();
    initializeSprite();
    setPosition(  x,  y);
}
Ship::~Ship()
{

}

//Functions
void Ship::render(sf::RenderTarget& target)
{
    target.draw(sprite);
    skin.render(target); //why window doesn't work? *widnow, Derenders window
}

void Ship::initializeTexture()
{
    //Loading text form a file
    if (!texture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space Shooter1\\Textures\\Space_ship2.png"))
    {
        std::cout<< "ERROR::Ship::initializeTexture:: Couldn't load thexture file."<<"\n";
    }

}

void Ship::initializeSprite()
{
    //Set the texture to the sprite
    sprite.setTexture(texture);

    //Resize sprite
    sprite.scale(1.f, 1.f);

}

void Ship::move(const float dirX, const float dirY)
{
    //sprite.move(movementSpeed * dirX, movementSpeed * dirY);
    sf::Vector2f pos=getPos();// tworzy structure of x and y
    setPosition(pos.x+movementSpeed* dirX, pos.y+movementSpeed * dirY);
}

const sf::Vector2f &Ship::getPos() const
{
    return sprite.getPosition();//sprite function which automaticly reads sprite's position
}

void Ship::attack()
{
    if(attackCooldown < attackCooldownMax)//adding to atackCooldown 0.3f untill 10.f, not sure what unit is f.
       attackCooldown += 0.3f;
}

const bool Ship::canAttack()
{
    if (attackCooldown >= attackCooldownMax)
    {
        attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Ship::inializeVariables()
{
    movementSpeed=initializeSpeed();

    attackCooldownMax = 10.f;
    attackCooldown = attackCooldownMax;//canAttack() return true and we can shoot
}

sf::FloatRect Ship::getBounds()
{
    return sprite.getGlobalBounds();
}

void Ship::setPosition(const float x, const float y) {

    XX=x;
    YY=y;
    sprite.setPosition(x, y);
    skin.setPosition(x,y);
}

float Ship::initializeSpeed() {
    movementSpeed = 1.1f;
    return movementSpeed;
}


