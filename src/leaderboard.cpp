#include "leaderboard.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace sf;

extern std::string playerRecordsFilepath;

Leaderboard::Leaderboard()
{
    font.loadFromFile("texture/font.ttf");

    unsigned int characterSize = 40;
    exitButton.setFont(font);
    exitButton.setOutlineColor(Color::Red);
    exitButton.setOutlineThickness(0.f);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit to mainmenu");
    exitButton.setPosition(20, 520);

    float x = 30, y = 30, dy = 80;
    for (size_t i = 0; i < 5; i++)
    {
        leaderboardText[i].setFont(font);
        leaderboardText[i].setFillColor(Color::White);
        leaderboardText[i].setOutlineColor(Color::Black);
        leaderboardText[i].setOutlineThickness(2.4f);
        leaderboardText[i].setCharacterSize(42);
        leaderboardText[i].setPosition(x, y + i * dy);
        leaderboardText[i].setLetterSpacing(1);
    }

    resetButton.setFont(font);
    resetButton.setOutlineColor(Color::Red);
    resetButton.setOutlineThickness(0.f);
    resetButton.setCharacterSize(characterSize);
    resetButton.setString("Reset\nleaderboard");
    resetButton.setPosition(360, 480);
}

int Leaderboard::draw(RenderWindow &window)
{
    window.setTitle("Leaderboard");
    Color gameBackground(111, 129, 214); // Цвет заднего фона (светло-голубой)

    fillLeaderboardText();
    Event event;
    while (true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return -1;
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
                return 0;
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                    return 0;
                if (IntRect(resetButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                {
                    remove(playerRecordsFilepath.c_str());
                    resetButton.setString("Reset\nsuccesful!");
                    resetButton.setFillColor(Color::Black);
                }
            }
        }

        window.clear(gameBackground);
        window.draw(exitButton);
        window.draw(resetButton);
        for (Text &g : leaderboardText)
            window.draw(g);
        window.display();
    }
}

void Leaderboard::fillLeaderboardText()
{
    std::vector <std::string> players(0);
    std::string input;
    std::ifstream file;
    file.open(playerRecordsFilepath);
    if (!file.is_open())
        return;

    getline(file, input, '\n');
    while (!file.eof())
    {
        players.push_back(input);
        getline(file, input, '\n');
    }

    for (auto &x : players)
    {
        for (size_t i = 0; i < x.size(); i++)
        {
            if (x[i] == ':')
            {
                x[i] = ' ';
                x.insert(i, " : ");
                break;
            }
        }
    }

    for (size_t z = 0; z < players.size(); z++)
    {
        leaderboardText[z].setString(players[z] + " sec");
    }
}
