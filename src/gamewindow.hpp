#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Gamewindow
{
private:
    Font font;

    Text exitButton;

    Clock gameTime;
public:
    Gamewindow();

    int draw(RenderWindow &window);
};

#endif // GAMEWINDOW_HPP
