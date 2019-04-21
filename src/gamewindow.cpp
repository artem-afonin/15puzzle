#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gamewindow.hpp"

using namespace sf;

static int boardBigArr[4][4];

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

    gameBoardBigTexture.loadFromFile("texture/4x4gameboard.png");
    gameBoardBig.setTexture(gameBoardBigTexture);
}

int Gamewindow::draw(RenderWindow &window, int gameDifficulty, int gameImage)
{
    window.setTitle("15-Puzzle GAME");
    Color gameBackground(111, 129, 214); // Цвет заднего фона (светло-голубой)
    std::ostringstream gameTimeString;
    Clock gameTime;

    for (int i = 0, count = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            boardBigArr[i][j] = ++count;

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
        drawBoard(window, gameDifficulty);
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

void Gamewindow::drawBoard(RenderWindow &window, int gameDifficulty)
{
    if (gameDifficulty == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (boardBigArr[i][j] != 16)
                {
                    gameBoardBig.setTextureRect(IntRect(115 * (boardBigArr[i][j] - 1), 0, 115, 115));
                    gameBoardBig.setPosition(70 + 115 * j, 10 + 115 * i);
                    window.draw(gameBoardBig);
                }
            }
        }
    }
}
