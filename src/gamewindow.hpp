#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Gamewindow
{
private:
    // ПЕРЕМЕННЫЕ
    Font font;

    Text exitButton;
    Text timerText;
    Text gameTimeText;

    Clock gameTimeClock;

    Texture gameBoardBigTexture;
    Sprite gameBoardBig;

    //МЕТОДЫ
    void colorExitButton(RenderWindow &window);
    void drawBoard(RenderWindow &window, int gameDifficulty);
public:
    Gamewindow();

    int draw(RenderWindow &window, int gameDifficulty, int gameImage);
};

#endif // GAMEWINDOW_HPP
