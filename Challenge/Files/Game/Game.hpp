/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 03/05/2023
 * Description: Assinatura de funções.
*/

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include<chrono>

//Número de circulos que aparecem no ecrã
#define MAXCIRCLES 50

class Game{
    public:
        //Construtor
        Game(float width, float height, int playerPlays);

        //Struct posicionamento dos circulos
        struct Position {
            float x, y;
        };

        //Assinatura de funções
        //Desenhar no ecra
        void draw(sf::RenderWindow& window);

        //Funções para receber dados aleatóreos
        float RandomRadious();
        sf::Color RandomColor();
        Position RandomPosition();

        //Receber informações
        int GetPlays();

        //Perceber se é verdade ou não
        bool CheckIfClickedCircle(sf::Event::MouseButtonEvent event);
        bool CheckIfPlaying();
        bool WinOrLose();

        //Estabelecer sistema de pontos
        void RemovePlays(sf::RenderWindow& window);
        void ManageIsPlaying(sf::RenderWindow& window);

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
