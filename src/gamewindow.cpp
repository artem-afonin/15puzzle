#include <sstream>
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
    exitButton.setOutlineColor(Color::Red);

    gameTimeText.setFont(font);
    gameTimeText.setCharacterSize(characterSize);
    gameTimeText.setPosition(400, 520);
}

int Gamewindow::draw(RenderWindow &window)
{
    window.setTitle("15-Puzzle GAME");
    Color gameBackground(111, 129, 214); // Цвет заднего фона (светло-голубой)
    std::ostringstream gameTimeString;
    Clock gameTime;

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

        gameTimeString << (int) gameTime.getElapsedTime().asSeconds();
        gameTimeText.setString("Time: " + gameTimeString.str());
        gameTimeString.str("");

        window.clear(gameBackground);
        window.draw(exitButton);
        window.draw(gameTimeText);
        window.display();
    }
}

void Gamewindow::colorExitButton(RenderWindow &window)
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
