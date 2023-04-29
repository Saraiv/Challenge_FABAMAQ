#include<iostream>
#include <SFML/Graphics.hpp>
#include"MainMenu.hpp"

int main(int argc, char** argv){
    //Creating window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Challenge!");
    
    //Setting up Main Menu
    MainMenu mainMenu(window.getSize().x, window.getSize().y);

    //Live window
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Up){
                    mainMenu.MoveUp();
                    break;
                }
                if(event.key.code == sf::Keyboard::Down){
                    mainMenu.MoveDown();
                    break;
                }
                if(event.key.code == sf::Keyboard::Return){
                    int optionSelected = mainMenu.MainMenuPressed();
                    std::cout << optionSelected << std::endl;

                    //Play
                    if(optionSelected == 0){
                        sf::RenderWindow play(sf::VideoMode(800,600), "Playing!");
                        while(play.isOpen()){
                            sf::Event playEvent;
                            while(play.pollEvent(playEvent)){
                                if(playEvent.type == sf::Event::Closed)
                                    play.close();
                                if(playEvent.type == sf::Event::KeyPressed){
                                    if(playEvent.key.code == sf::Keyboard::Escape){
                                        play.close();
                                    }
                                }
                            }

                            play.display();
                        }
                    }

                    //Credits In
                    if(optionSelected == 1){
                        mainMenu.RemoveCredits();
                        std::cout << mainMenu.GetCredits() << std::endl;
                    }

                    if(optionSelected == 2){
                        mainMenu.ReturnCredits();
                        std::cout << mainMenu.GetCredits() << std::endl;
                    }

                    //Exit
                    if(optionSelected == 3){
                        window.close();
                    }
                }
            }
        }

        window.clear();
        mainMenu.draw(window);
        window.display();
    }

    return 0;
}