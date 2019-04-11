#include <SFML/Graphics.hpp>
#include "rules.hpp"

using namespace sf;

Rules::Rules()
{
    font.loadFromFile("texture/font.ttf");

    unsigned int characterSize = 45;

    exitButton.setFont(font);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit settings");
    exitButton.setPosition(30, 500);
}

int Rules::draw(RenderWindow &window)
{
    window.setTitle("Rules");
    Color menuBackground(111, 129, 214);

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

        colorExitButton(window);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
            {
                return 0;
            }
        }
        window.clear(menuBackground);
        window.draw(exitButton);
        window.display();
    }
}
void Rules::colorExitButton(RenderWindow &window)
{
    if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
    {
        exitButton.setOutlineThickness(2);
        exitButton.setOutlineColor(Color::Red);
    }
    else
    {
        exitButton.setOutlineThickness(0);
        exitButton.setOutlineColor(Color::White);
    }
}
