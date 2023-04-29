#include"MainMenu.hpp"

//Construtor
MainMenu::MainMenu(float width, float height){
    if(!font.loadFromFile("Fonts/font.TTF"))
        std::cout << "No font!";

    //Text "Buttons"
    //Credits
    creditsText.setFont(font);
    creditsText.setFillColor(sf::Color::White);
    creditsText.setString(std::to_string(credits));
    creditsText.setCharacterSize(24);
    creditsText.setPosition(24.f, 24.f);

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

    mainMenuSelected = 0;
    credits = 50;
}

//Destrutor
MainMenu::~MainMenu(){

}

void MainMenu::draw(sf::RenderWindow& window){
    for(int i= 0; i < MaxMM; ++i){
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveUp(){
    if(mainMenuSelected - 1 >= 0){
        mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

        mainMenuSelected--;

        mainMenu[mainMenuSelected].setFillColor(sf::Color::Cyan);
    }
}

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

void MainMenu::RemoveCredits(){
    credits--;
}

void MainMenu::ReturnCredits(){
    credits++;
}

int MainMenu::GetCredits(){
    return credits;
}