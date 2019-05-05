#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gamewindow.hpp"

using namespace sf;
using namespace std;

int y_null = 3, x_null = 3;//координаты пустой клетки

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
            puzzle[i][j].sprite.setTexture(gameBoardBigTexture);
            puzzle[i][j].sprite.setTextureRect(IntRect(115 * count++, 0, 115, 115));
        }
    }

    for (int i = 0, count = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            puzzle[i][j].number = ++count;
    puzzle[x_null][y_null].number = 0;
}

int Gamewindow::draw(RenderWindow &window, int gameDifficulty, int gameImage)
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
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                {
                    return 0;
                }
            }
        }

        colorExitButton(window);
        colorPuzzles(Mouse::getPosition(window), gameDifficulty);
        gameTimeString << (int) gameTime.getElapsedTime().asSeconds();
        gameTimeText.setString("Time: " + gameTimeString.str());
        gameTimeString.str("");

        window.clear(gameBackground);
        window.draw(exitButton);
        window.draw(gameTimeText);
        drawBoard(window, gameDifficulty);
        window.display();

        movePuzzle(Mouse::getPosition(window), window, gameDifficulty);
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
                if (IntRect(puzzle[i][j].sprite.getGlobalBounds()).contains(mousePosition))
                {
                    puzzle[i][j].sprite.setColor(Color::Red);
                }
                else
                {
                    puzzle[i][j].sprite.setColor(Color::White);
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
                if (puzzle[i][j].number != 0 )
                {
                    dx = 115 * ((puzzle[i][j].number - 1) % 4);
                    dy = 115 * ((puzzle[i][j].number - 1) / 4);
                    puzzle[i][j].sprite.setPosition(70 + dx, 20 + dy);
                    window.draw(puzzle[i][j].sprite);
                }
            }
        }
    }
}

void Gamewindow::movePuzzle(Vector2i mousePosition, RenderWindow &window, int gameDifficulty)
{
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (IntRect(puzzle[i][j].sprite.getGlobalBounds()).contains(mousePosition))
                {
                    puzzle[x_null][y_null].number = puzzle[i][j].number;
                    puzzle[i][j].number = 0;
                    x_null = i; y_null = j;
                    cout << x_null << y_null << "   ";
                }
            }
        }
    }
}
