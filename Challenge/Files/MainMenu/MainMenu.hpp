/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 03/05/2023
 * Description: Assinatura de funções do menu.
*/

#include<iostream>
#include <SFML/Graphics.hpp>

//Número de opções que aparecem no menu
#define MaxMM 4

class MainMenu{
    public:
        //Construtor
        MainMenu(float width, float height);

        //Assinatura de funções
        //Desenhar no ecra
        void draw(sf::RenderWindow& window);

        //Opções para mexer no menu e opção selecionada
        void MoveUp();
        void MoveDown();
        int MainMenuPressed(){ return mainMenuSelected; }

        //Tratar dos créditos do jogador
        void RemoveCredits();
        void ReturnCredits();
        int GetCredits();
        void GiveCredits(int givenCredits, sf::RenderWindow& window);

        //Atualizar o texto no ecrã
        void UpdateText();

        //Receber valor apostado
        int GetBettingValue();

        //Verificar se pode jogar ou não
        bool CheckIfCanPlay();

        //Destrutor
        ~MainMenu();

    private:
        int mainMenuSelected, credits, bettingValue, startingCredits;
        sf::Font font;
        sf::Text mainMenu[MaxMM], creditsText, bettingText;
};