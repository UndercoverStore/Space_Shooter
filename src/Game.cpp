#include "Game.h"
#include "Bullet.h"
#include "Unit.h"
#include <iostream>
#include <sstream>

//const sf::Time Engine::TimePerFrame = seconds (1.f/60.f); //second option to set Frame limit

void Game::initializeWindow()//creating window
{
    window = new sf::RenderWindow(sf::VideoMode(800,600), "Space Shooter!", sf::Style::Default);
    window->setFramerateLimit(144);
    //window.setFramerateLimit(FPS); //second option to set Frame limit
}//////////////////////////////////////////
//Constractor/Destructor
Game::Game()
{
    initializeWindow();
    initializeTextures();
    initializeFonts();//
    initializeShip();
    initializeAsteroid();
}
Game::~Game()
{
    delete window;
    delete ship;

    //Deleting textures
    for(auto& i : textures)
    {
        delete i.second;//daleting second part of pairing, which are texture.
    }
    //Deleting bulelts
    for(auto* i : bullets)
    {
        delete i;
    }
    //Delete asteroids
    for (auto *i : this->asteroids)
    {
        delete i;
    }
}

//Functions
void Game::run()
{
    while (window->isOpen() && !gameOver)
    {
        update();
        render();
    }
}

void Game::initializeTextures()
{
    textures["Bullet"] = new sf::Texture();
    textures["Bullet"] -> loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space Shooter1\\Textures\\Bullet.png");
}

void Game::pollEvents()
{
    sf::Event eve;
    while (window->pollEvent(eve))
    {
        if (eve.Event::type ==sf::Event::Closed)
            window->close();
        if (eve.Event::KeyPressed && eve.Event::key.code ==sf::Keyboard::Escape)
            window->close();
    }
}

void Game::updateInput()
{
    //Ship movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        ship->move(-3.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        ship->move(3.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        ship->move(0.f, -3.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        ship->move(0.f, 3.f);

    //Mouse click
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ship->canAttack())//mouse click && cooldown
    {
        bullets.push_back(new Bullet(textures["Bullet"], ship->getPos().x+ ship->getBounds().width/2.f, ship->getPos().y, 0.f, -1.f, 5.f));//pushing bullet into arrey
    }
}

void Game::update()
{
    pollEvents();

    updateInput();
    ship->attack();
    rangeOfMotion();
    updateBullets();
    updateAsteroids();
    Combat();

    updateHP();
    setHealthPoints();
}

void Game::render()
{
    window->clear();
    //Drawing everything in here:
    ship->render(*window); //why window doesn't work? *widnow, Derenders window


    for (auto *bullet: bullets)
    {
        bullet->render(window);
    }

    for (auto *asteroid : asteroids)
    {
        asteroid->render(window);
    }
    drawText();
    window->display();//update the displayed image in the graphics window;
}

void Game::initializeShip()
{
    ship = new Ship();
}
void Game::initializeAsteroid()
{
    spawnTimerMax = 50.f;
    spawnTimer = spawnTimerMax;
}
void Game::updateBullets()
{
    unsigned counter= 0;
    for (auto *bullet: bullets)
    {
        bullet->update();

        if (bullet->getBounds().top + bullet->getBounds().height <= 0.f)// bullet which is out of the top of the screen
        {
            delete bullets.at(counter); //delete adress of that bullet
            bullets.erase(bullets.begin() + counter);//delete bullet
            --counter;//once we remove bullet form vector we also have to delate it's iterator.
        }
        ++counter;
        //std::cout<<bullets.size()<<"\n";
    }
}

void Game::updateAsteroids()
{
    //Spawning
    spawnTimer += 0.1f;
    if (spawnTimer >= spawnTimerMax)
    {
         *this+(new Asteroid(  rand() % 720+25.f,-100.f));
         //*this+ is overload + meaning asteroids.push_back(A);
         spawnTimer = 0.f;
    }

    unsigned counter= 0;
    for (auto *asteroid: asteroids)
    {
        asteroid->update();

        if (asteroid->getBounds().top >= window->getSize().y)// asteroid which is out of the bottom of the screen
        {
            delete asteroids.at(counter); //delete adress of that asteroid
            healthPoints--;
            asteroids.erase(asteroids.begin() + counter);//delete asteroid from vector
            --counter;//once we remove asteroid form vector we also have to delate it's iterator.
        }
        ++counter;
        //std::cout<<"Asteroids ammount:"<<asteroids.size()<<"\n";
    }
}

void Game::rangeOfMotion()
{
    //Left limitation of the range of motion
    if (ship->getBounds().left < 0.f)
    {
        ship->setPosition(0.f, ship->getBounds().top);
    }

    //Right limitation of the range of motion
    else if (ship->getBounds().left + ship->getBounds().width >= window->getSize().x)
    {
        ship->setPosition(window->getSize().x - ship->getBounds().width, ship->getBounds().top);
    }

    //Top limitation of the range of motion
    if (ship->getBounds().top < 0.f)
    {
        ship->setPosition(ship->getBounds().left, 0.f);
    }

    //Bottom limitation of the range of motion
    else if (ship->getBounds().top + ship->getBounds().height >= window->getSize().y)
    {
        ship->setPosition(ship->getBounds().left, window->getSize().y - ship->getBounds().height);
    }
}

void Game::Combat()
{
    for (int i=0; i< asteroids.size(); i++)
    {
        for(int j=0; j < bullets.size() ; j++)
        if (asteroids[i]->getBounds().intersects(bullets[j]->getBounds()))
        {
            //Deleting asteroids which got hit
            delete asteroids[i];
            asteroids.erase(asteroids.begin() + i);//delete asteroid from vector

            //Deleting bullets which got hit
            delete bullets[j];
            bullets.erase(bullets.begin() + j);//delete bullets from vector
        }
    }
}


void Game::initializeFonts()
{
    //Load Fonts
    if(!font.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space Shooter1\\Fonts\\RobotoSlab-ExtraBold.ttf"));
    {
    //std::cout<< "Coundln't load fonts"<<std::endl;
    }
}
void Game::updateHP() {
    if (healthPoints == 0)
        gameOver = true;

}

void Game::drawText() {
    window->draw(text);
}

void Game::operator + (Asteroid *A)
{
    asteroids.push_back(A);
}

void Game::setHealthPoints() {
    //set text
    text.setPosition(200.f, 0.f);
    text.setFont(this->font);
    std::string stringText="Healthpoints: ";
    //text.setString(stringText + std::to_string(healthPoints));//+ std::to_string(healthPoints));
    std::string fullText = stringText + std::to_string(healthPoints);
    text.setString(fullText);

    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
}

std::ostream& operator<<(std::ostream& os, const Game obj)
{
    std::ostringstream ss;
    ss << obj.stringText1;

    // Przekazanie reprezentacji wartości do strumienia os
    os << ss.str();

    return os;
}

void Game::showGameOver()
{
    Game obj;
    if (healthPoints == 0)
        std::cout<< obj;
}

Game& Game::operator=(const Game& other)
{
    if (this != &other) {
        score = other.score;
    }
    return *this;
}
