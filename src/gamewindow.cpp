#include <sstream>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "gamewindow.hpp"

using namespace sf;

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

    for (int i = 0, count = 0; i < 4; i++) //заполнение номеров, позиций и текстур
    {
        for (int j = 0; j < 4; j++)
        {
            puzzle[i][j].number = count + 1;
            puzzle[i][j].position = count + 1;
            puzzle[i][j].sprite.setTexture(gameBoardBigTexture);
            puzzle[i][j].sprite.setTextureRect(IntRect(115 * count++, 0, 115, 115));
        }
    }

    gameNullTexture.loadFromFile("texture/nullImage.png");// текстура пустой области
    puzzle[3][3].sprite.setTexture(gameNullTexture);
    puzzle[3][3].sprite.setTextureRect(IntRect(0, 0, 115, 115));
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

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (IntRect(puzzle[i][j].sprite.getGlobalBounds()).contains(Mouse::getPosition(window)))
                        {
                            movePuzzle(i, j);
                        }
                    }
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
                if (puzzle[i][j].position != 0 )
                {
                    dx = 115 * ((puzzle[i][j].position - 1) % 4);
                    dy = 115 * ((puzzle[i][j].position - 1) / 4);
                    puzzle[i][j].sprite.setPosition(70 + dx, 20 + dy);
                    window.draw(puzzle[i][j].sprite);
                }
           }
        }
    }
}

void Gamewindow::movePuzzle(int i, int j)
{
                {
                    int y_zero = (puzzle[x_null][y_null].position - 1)/4;
                    int x_zero = (puzzle[x_null][y_null].position - 1)%4;

                    int y = (puzzle[i][j].position - 1)/4;
                    int x = (puzzle[i][j].position - 1)%4;

                    if ((abs(y_zero - y)) + (abs(x_zero - x)) == 1)
                    {
                        int temp = puzzle[x_null][y_null].position;
                        puzzle[x_null][y_null].position = puzzle[i][j].position;
                        puzzle[i][j].position = temp;
                    }
                    else return;
               }
}
