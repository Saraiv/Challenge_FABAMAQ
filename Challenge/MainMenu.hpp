#include<iostream>
#include <SFML/Graphics.hpp>

#define MaxMM 4

class MainMenu{
    public:
        //Construtor
        MainMenu(float width, float height);

        void draw(sf::RenderWindow& window);
        void MoveUp();
        void MoveDown();
        int MainMenuPressed(){
            return mainMenuSelected;
        }
        void RemoveCredits();
        void ReturnCredits();
        int GetCredits();

        //Destrutor
        ~MainMenu();

    private:
        int mainMenuSelected;
        int credits;
        sf::Font font;
        sf::Text mainMenu[MaxMM];
        sf::Text creditsText;
};