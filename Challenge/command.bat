g++ -c ./Files/Challenge.cpp ./Files/MainMenu/MainMenu.hpp ./Files/MainMenu/MainMenu.cpp ./Files/Game/Game.hpp ./Files/Game/Game.cpp -I "D:\work\FABAMAQ\Challenge\SFML-2.5.1\include"

g++ Challenge.o MainMenu.o Game.o -o executable -L "D:\work\FABAMAQ\Challenge\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system