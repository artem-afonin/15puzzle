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
    for (int i = 0, count = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gameBoardBig[i][j].setTexture(gameBoardBigTexture);
            gameBoardBig[i][j].setTextureRect(IntRect(115 * count++, 0, 115, 115));
        }
    }
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
        colorPuzzles(Mouse::getPosition(window), gameDifficulty);

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
    }
    else
    {
        exitButton.setOutlineThickness(0);
    }
}

void Gamewindow::colorPuzzles(Vector2i mousePosition, int gameDifficulty)
{
    if (gameDifficulty == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (IntRect(gameBoardBig[i][j].getGlobalBounds()).contains(mousePosition))
                {
                    gameBoardBig[i][j].setColor(Color::Red);
                }
                else
                {
                    gameBoardBig[i][j].setColor(Color::White);
                }
            }
        }
    }
}

void Gamewindow::drawBoard(RenderWindow &window, int gameDifficulty)
{
    int dx = 0, dy = 0;
    if (gameDifficulty == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (boardBigArr[i][j] != 16)
                {
                    dx = 115 * ((boardBigArr[i][j] - 1) % 4);
                    dy = 115 * ((boardBigArr[i][j] - 1) / 4);
                    gameBoardBig[i][j].setPosition(70 + dx, 20 + dy);
                    window.draw(gameBoardBig[i][j]);
                }
            }
        }
    }
}
