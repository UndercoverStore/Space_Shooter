#include "Bullet.h"

//Constractor/Destructor
Bullet::Bullet(sf::Texture* texture,float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed)
{
    shape.setTexture(*texture);//setTexture-adjusts the scope of the object to its graphical representation


   shape.setPosition(pos_x,pos_y);
   direction.x= dir_X;//currently not used, might be useful for direction shooting
   direction.y= dir_Y;
   movementSpeed= movement_speed;
}
Bullet::~Bullet()
{

}

//Functions
void Bullet::update()
{
    //Bullet movement
    shape.move(movementSpeed * direction);//should work
}

void Bullet::render(sf::RenderTarget *target)
{
    target->draw(shape);
}

const sf::FloatRect Bullet::getBounds() const//rectangle boundings of the vertex array
{
    return shape.getGlobalBounds();
}

