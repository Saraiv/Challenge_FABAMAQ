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
        void GiveCredits(int givenCredits, sf::RenderWindow& window);
        void UpdateText();
        int GetCredits();
        int GetBettingValue();
        bool CheckIfCanPlay();

        //Destrutor
        ~MainMenu();

    private:
        int mainMenuSelected, credits, bettingValue, startingCredits;
        sf::Font font;
        sf::Text mainMenu[MaxMM], creditsText, bettingText;
};