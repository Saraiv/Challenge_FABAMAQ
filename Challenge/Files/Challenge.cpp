#include<iostream>
#include <SFML/Graphics.hpp>
#include"./MainMenu/MainMenu.hpp"
#include"./Game/Game.hpp"

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

                    //Play
                    if(optionSelected == 0 && mainMenu.CheckIfCanPlay()){
                        sf::RenderWindow play(sf::VideoMode(800,600), "Playing!");
                        int bettingValue = mainMenu.GetBettingValue();
                        int credits = mainMenu.GetCredits();
                        Game game(play.getSize().x, play.getSize().y, mainMenu.GetBettingValue());

                        while(play.isOpen()){
                            play.clear();
                            sf::Event playEvent;
                            while(play.pollEvent(playEvent)){
                                if(playEvent.type == sf::Event::Closed){
                                    play.close();
                                    mainMenu.UpdateText();
                                }

                                if(playEvent.type == sf::Event::KeyPressed){
                                    if(playEvent.key.code == sf::Keyboard::Escape){
                                        play.close();
                                        mainMenu.UpdateText();
                                    }

                                    if(playEvent.key.code == sf::Keyboard::Return){
                                        game.RemovePlays(play);
                                    }
                                }

                                if(playEvent.type == sf::Event::MouseButtonPressed && game.CheckIfPlaying()){
                                    if (playEvent.mouseButton.button == sf::Mouse::Left 
                                        && game.CheckIfClickedCircle(playEvent.mouseButton))
                                        std::cout << "Sucess!" << std::endl;
                                    else std::cout << "Missed!" << std::endl;
                                }
                                
                            }
                            game.ManageIsPlaying(play);
                            
                            if(game.WinOrLose()){
                                int givenPoints = mainMenu.GetBettingValue() * 2;
                                mainMenu.GiveCredits(givenPoints, play);
                                mainMenu.UpdateText();
                                play.close();
                            }

                            game.draw(play);
                            play.display();
                        }
                    }

                    //Credits In
                    if(optionSelected == 1){
                        mainMenu.RemoveCredits();
                    }

                    if(optionSelected == 2){
                        mainMenu.ReturnCredits();
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