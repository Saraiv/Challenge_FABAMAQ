#include"Game.hpp"

//Construtor
Game::Game(float width, float height, int playerPlays){
    if(!font.loadFromFile("Fonts/font.TTF"))
        std::cout << "No font!";

    srand(time(NULL));

    for(int i = 0; i < MAXCIRCLES; i++){
        Position position = RandomPosition();
        int randomRadious = Game::RandomRadious();
        circles[i].setRadius(randomRadious);
        circles[i].setFillColor(Game::RandomColor());
        circles[i].setPosition(position.x, position.y);
    }

    playsText.setFont(font);
    playsText.setFillColor(sf::Color::White);
    playsText.setString(std::to_string(playerPlays));
    playsText.setCharacterSize(24);
    playsText.setPosition(24.f, 560.f);

    startGameText.setFont(font);
    startGameText.setFillColor(sf::Color::Cyan);
    startGameText.setString("START");
    startGameText.setCharacterSize(60);
    startGameText.setPosition(300.f, 530.f);

    this->playerPlays = playerPlays;
    potentialPoints = playerPlays;
    points = 0;
    isCircleClickable, isPlaying = false;
    timerLimit = 5.f;
    speed = 1.f;
}

//Destrutor
Game::~Game(){

}

void Game::draw(sf::RenderWindow& window){
    window.draw(playsText);
    window.draw(startGameText);
    for(int i = 0; i < MAXCIRCLES; ++i){
        window.draw(circles[i]);
    }
}

float Game::RandomRadious(){
    return static_cast<float>(10 + rand() % 10);
}

void Game::RemovePlays(sf::RenderWindow& window){
    if(playerPlays > 0 && !WinOrLose()){
        playsText.setString(std::to_string(--playerPlays));
        isPlaying = true;
        isCircleClickable = true;
        timer = 0.f;
        clock.restart();
    }
    else if(WinOrLose()){
        std::cout << "O jogador ganhou!" << std::endl;

        isPlaying = false;
        isCircleClickable = false;
    }
    else {
        std::cout << "As jogadas acabaram!" << std::endl;
        isPlaying = false;
        isCircleClickable = false;
    }
}

int Game::GetPlays(){
    return playerPlays;
}

Game::Position Game::RandomPosition(){
    Game::Position pos;
    pos.x = static_cast<float>(rand() % 800);
    pos.y = static_cast<float>(rand() % 600);

    return pos;
}

sf::Color Game::RandomColor(){
    int random = rand() % 5;
    switch (random) {
        case 0:
            return sf::Color::Blue;
        case 1:
            return sf::Color::Red;
        case 2:
            return sf::Color::Green;
        case 3:
            return sf::Color::Yellow;
        case 4:
            return sf::Color::White;
        default:
            return sf::Color::White;
    }
}

bool Game::CheckIfClickedCircle(sf::Event::MouseButtonEvent event){
    for(int i = 0; i < MAXCIRCLES; i++){
        if(circles[i].getGlobalBounds().contains(event.x, event.y) && isCircleClickable){
            circles[i].setPosition(-1000.0f, -1000.0f);
            points++;
            return true;
        }
    }

    return false;
}

bool Game::WinOrLose(){
    return points == MAXCIRCLES ? true : false;
}

bool Game::CheckIfPlaying(){
    return isPlaying ? true : false;
}

void Game::ManageIsPlaying(sf::RenderWindow& window){
    if(isPlaying && !WinOrLose()){
        timer = clock.getElapsedTime().asSeconds();

        for(int i = 0; i < MAXCIRCLES; i++){
            circles[i].move(timer * speed, .0f);
            if (circles[i].getPosition().x > window.getSize().x + circles[i].getRadius())
                circles[i].setPosition(-circles[i].getRadius(), circles[i].getPosition().y);
        }

        isCircleClickable = true;
        if (timer > timerLimit){
            isPlaying = false;
            isCircleClickable = false;
        }
    }
}