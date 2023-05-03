/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 03/05/2023
 * Description: Módulos de implementação do menu.
*/

#include"MainMenu.hpp"

/**
 * Construtor do menu inicial
 * @param [in] width // Largura da janela
 * @param [in] height // Altura da janela
*/
MainMenu::MainMenu(float width, float height){
    if(!font.loadFromFile("Fonts/font.TTF"))
        std::cout << "No font!";
    
    credits = 50;
    bettingValue = 0, mainMenuSelected = 0;
    startingCredits = credits;

    //Text "Buttons"
    //Credits
    creditsText.setFont(font);
    creditsText.setFillColor(sf::Color::White);
    creditsText.setString(std::to_string(credits));
    creditsText.setCharacterSize(24);
    creditsText.setPosition(24.f, 24.f);

    //Betting
    bettingText.setFont(font);
    bettingText.setFillColor(sf::Color::White);
    bettingText.setString(std::to_string(bettingValue));
    bettingText.setCharacterSize(24);
    bettingText.setPosition(24.f, 560.f);

    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setString("PLAY");
    mainMenu[0].setCharacterSize(60);
    mainMenu[0].setPosition(200.f, 100.f);

    //Credits In
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("CREDITS IN");
    mainMenu[1].setCharacterSize(60);
    mainMenu[1].setPosition(200.f, 200.f);

    //Credits Out
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("CREDITS OUT");
    mainMenu[2].setCharacterSize(60);
    mainMenu[2].setPosition(200.f, 300.f);

    //Exit
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("EXIT");
    mainMenu[3].setCharacterSize(60);
    mainMenu[3].setPosition(200.f, 400.f);
}

/**
 * Destrutor do menu inicial
*/
MainMenu::~MainMenu(){

}

/**
 * Desenhar no ecrã tudo o que foi criado
 * @param [in] window // Receber por parametro a própria janela
*/
void MainMenu::draw(sf::RenderWindow& window){
    window.draw(creditsText);
    window.draw(bettingText);
    for(int i= 0; i < MaxMM; ++i){
        window.draw(mainMenu[i]);
    }
}

/**
 * Mover a opção selecionada do menu para cima
*/
void MainMenu::MoveUp(){
    if(mainMenuSelected - 1 >= 0){
        mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

        mainMenuSelected--;

        mainMenu[mainMenuSelected].setFillColor(sf::Color::Cyan);
    }
}

/**
 * Mover a opção selecionada do menu para baixo
*/
void MainMenu::MoveDown(){
    if(mainMenuSelected - 1 <= MaxMM){
        mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

        mainMenuSelected++;

        if(mainMenuSelected == 4){
            mainMenuSelected = 0;
        }

        mainMenu[mainMenuSelected].setFillColor(sf::Color::Cyan);
    }
}

/**
 * Remove os créditos que o player decide remover, um a um e acrescenta o valor apostado
 * já atualizando o texto no ecrã
*/
void MainMenu::RemoveCredits(){
    if(credits > 0){
        credits--;
        bettingValue++;
        creditsText.setString(std::to_string(credits));
        bettingText.setString(std::to_string(bettingValue));
    }
    else
        std::cout << "Não tem créditos suficientes para apostar!" << std::endl;
}

/**
 * Adiciona os créditos que o player decide adicionar, um a um e remove o valor apostado
 * já atualizando o texto no ecrã
*/
void MainMenu::ReturnCredits(){
    if(credits > 0 && credits < startingCredits && bettingValue > 0){
        credits++;
        bettingValue--;
        creditsText.setString(std::to_string(credits));
        bettingText.setString(std::to_string(bettingValue));
    }
    else
        std::cout << "Não há mais créditos para retornar!" << std::endl;
}

/**
 * Retorna os créditos do jogador
 * @param [out] credits
*/
int MainMenu::GetCredits(){
    return credits;
}

/**
 * Dá os créditos ganhos pelo jogador e fecha a janela
 * @param [in] givenCredits //Créditos apostados
 * @param [in] window //Própria janela do jogo
*/
void MainMenu::GiveCredits(int givenCredits, sf::RenderWindow& window){
    credits += givenCredits;
    window.close();
}

/**
 * Retorna o valor apostado pelo jogador
 * @param [out] bettingValue
*/
int MainMenu::GetBettingValue(){
    return bettingValue;
}

/**
 * Verifica se o jogador apostou ou não.
 * @param [out] bool
*/
bool MainMenu::CheckIfCanPlay(){
    return (bettingValue > 0) ? true : false;
}

/**
 * Atualiza o texto no ecrã.
*/
void MainMenu::UpdateText(){
    bettingValue = 0;
    creditsText.setString(std::to_string(credits));
    bettingText.setString(std::to_string(bettingValue));
}