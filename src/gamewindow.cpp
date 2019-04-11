#include <SFML/Graphics.hpp>
#include "gamewindow.hpp"

using namespace sf;

Gamewindow::Gamewindow()
{
    font.loadFromFile("texture/font.ttf");

    unsigned int characterSize = 40;

    exitButton.setFont(font);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit to main menu");
    exitButton.setPosition(20, 520);
}

int Gamewindow::draw(RenderWindow &window)
{
    window.setTitle("15-Puzzle GAME");
    Color gameBackground(111, 129, 214); // Цвет заднего фона (светло-голубой)

    Event event;

    while(true)
    {
        while (window.pollEvent(event)) // проверка нажатия на крестик (закрыть программу)
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return -1;
            }
        }

        window.clear(gameBackground);
        window.draw(exitButton);
        window.display();
    }
}
