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

    //МЕТОДЫ
    void colorExitButton(RenderWindow &window);
public:
    Gamewindow();

    int draw(RenderWindow &window);
};

#endif // GAMEWINDOW_HPP
