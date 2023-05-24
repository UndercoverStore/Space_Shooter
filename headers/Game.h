#ifndef SPACE_SHOOTER1_GAME_H
#define SPACE_SHOOTER1_GAME_H
#include "Ship.h"
#include <map>
#include "Bullet.h"
#include "Asteroid.h"
#include "Skin.h"

class Game
{
private:
    //Window
    sf::RenderWindow* window;

    //Textures
    std::map<std::string, sf::Texture*> textures;//matches string wtih textures

    //Text
    sf::Font font;
    sf::Text text;

    //Ship
    Ship* ship;//* not to create coppies cuz in bigger game it might lag
    //Skin* skin;//* not to create coppies cuz in bigger game it might lag

    //Vector for bullets
    std::vector<Bullet*> bullets;

    //Vector for asteroids
    std::vector<Asteroid*> asteroids;

    void operator + (Asteroid *A);


    //Variables
    float spawnTimer=0;
    float spawnTimerMax=10;
    int healthPoints=3;
    bool gameOver= false;
    std::string stringText1="Game over.";

    //Private functions
    void initializeWindow();
    void initializeFonts();
    void updateHP() ;
    void drawText();
    void initializeTextures();
    void initializeShip();
    void initializeAsteroid();
    void updateAsteroids();
    void rangeOfMotion();
    void Combat();

public:
    Game();
    virtual ~Game();

    friend std::ostream& operator<<(std::ostream& os, const Game obj);
    //Functions
    void run();//Putting everything in between run and render

    void pollEvents();
    void updateInput();
    void updateBullets();
    void setHealthPoints();
    void update();
    void showGameOver();
    Game& operator=(const Game& other);
    int score;

    void render();//Drawing everything
};

#endif //SPACE_SHOOTER1_GAME_H
