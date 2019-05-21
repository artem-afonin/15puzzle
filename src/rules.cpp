#include <SFML/Graphics.hpp>
#include "rules.hpp"

using namespace sf;

Rules::Rules()
{
    font.loadFromFile("texture/font.ttf");

    unsigned int characterSize = 45;
    unsigned int rulesSize = 25;
    float x=15, y=15;

    exitButton.setFont(font);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit settings");
    exitButton.setPosition(30, 500);
    exitButton.setOutlineColor(Color::Red);

    float counter = 0;
    for (Text &z : gameRules)
    {
        z.setFont(font);
        z.setCharacterSize(rulesSize);
        z.setPosition(x, y + 50.f * counter++);

    }

    gameRules[0].setString(L"Игровое поле представляет собой матрицу");
    gameRules[1].setString(L"4х4 (3х3) клеток, на котором по порядку");
    gameRules[2].setString(L"располагаются цифры от 1 до 15 (от 1 до 9). ");
    gameRules[3].setString(L"Последняя клетка – пустая. Клетки");
    gameRules[4].setString(L"перемешиваются. Задача игрока состоит в том,");
    gameRules[5].setString(L"чтобы восстановить их первоначальное");
    gameRules[6].setString(L"правильное расположение. Делать это можно");
    gameRules[7].setString(L"лишь путем перемещения на пустую клетку");
    gameRules[8].setString(L"другой, соседней с ней клетки (расположенной");
    gameRules[9].setString(L"слева, справа, сверху или снизу от пустой).");
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

            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
                return 0;

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                {
                    return 0;
                }
            }
        }

        colorExitButton(window);

        window.clear(menuBackground);
        window.draw(exitButton);
        for (Text &x : gameRules)
            window.draw(x);
        window.display();
    }
}
void Rules::colorExitButton(RenderWindow &window)
{
    if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
        exitButton.setOutlineThickness(2);
    else
        exitButton.setOutlineThickness(0);
}
