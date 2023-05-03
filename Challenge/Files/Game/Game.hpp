#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include<chrono>

#define MAXCIRCLES 10

class Game{
    public:
        //Construtor
        Game(float width, float height, int playerPlays);

        void draw(sf::RenderWindow& window);

        struct Position {
            float x, y;
        };

        float RandomRadious();
        sf::Color RandomColor();
        Position RandomPosition();
        void RemovePlays(sf::RenderWindow& window);
        int GetPlays();
        void ManageIsPlaying(sf::RenderWindow& window);
        bool CheckIfClickedCircle(sf::Event::MouseButtonEvent event);
        bool CheckIfPlaying();
        bool WinOrLose();

        //Destrutor
        ~Game();

    private:
        sf::CircleShape circles[MAXCIRCLES];
        sf::Text playsText, startGameText;
        sf::Font font;
        sf::Clock clock;
        float timer, timerLimit, speed;
        int playerPlays, points, potentialPoints;
        bool isPlaying, isCircleClickable;
};