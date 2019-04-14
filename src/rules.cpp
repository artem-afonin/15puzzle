#include <SFML/Graphics.hpp>
#include "rules.hpp"

using namespace sf;

Rules::Rules()
{
    font.loadFromFile("texture/font.ttf");

    unsigned int characterSize = 45;
    unsigned int rulesSize = 25;
    int x=15, y=15;

    exitButton.setFont(font);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit settings");
    exitButton.setPosition(30, 500);

    gameRules1.setFont(font);
    gameRules1.setCharacterSize(rulesSize);
    gameRules1.setString(L"Игровое поле представляет собой матрицу");
    gameRules1.setPosition(x, y);

    gameRules2.setFont(font);
    gameRules2.setCharacterSize(rulesSize);
    gameRules2.setString(L"4х4 (3х3) клеток, на котором по порядку");
    gameRules2.setPosition(x, y+50);

    gameRules3.setFont(font);
    gameRules3.setCharacterSize(rulesSize);
    gameRules3.setString(L"располагаются цифры от 1 до 15 (от 1 до 9). ");
    gameRules3.setPosition(x, y+100);

    gameRules4.setFont(font);
    gameRules4.setCharacterSize(rulesSize);
    gameRules4.setString(L"Последняя клетка – пустая. Клетки");
    gameRules4.setPosition(x, y+150);

    gameRules5.setFont(font);
    gameRules5.setCharacterSize(rulesSize);
    gameRules5.setString(L"перемешиваются. Задача игрока состоит в том,");
    gameRules5.setPosition(x, y+200);

    gameRules6.setFont(font);
    gameRules6.setCharacterSize(rulesSize);
    gameRules6.setString(L"чтобы восстановить их первоначальное");
    gameRules6.setPosition(x, y+250);

    gameRules7.setFont(font);
    gameRules7.setCharacterSize(rulesSize);
    gameRules7.setString(L"правильное расположение. Делать это можно");
    gameRules7.setPosition(x, y+300);

    gameRules8.setFont(font);
    gameRules8.setCharacterSize(rulesSize);
    gameRules8.setString(L"лишь путем перемещения на пустую клетку");
    gameRules8.setPosition(x, y+350);

    gameRules9.setFont(font);
    gameRules9.setCharacterSize(rulesSize);
    gameRules9.setString(L"другой, соседней с ней клетки (расположенной");
    gameRules9.setPosition(x, y+400);

    gameRules10.setFont(font);
    gameRules10.setCharacterSize(rulesSize);
    gameRules10.setString(L"слева, справа, сверху или снизу от пустой).");
    gameRules10.setPosition(x, y+450);
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

        window.draw(gameRules1);
        window.draw(gameRules2);
        window.draw(gameRules3);
        window.draw(gameRules4);
        window.draw(gameRules5);
        window.draw(gameRules6);
        window.draw(gameRules7);
        window.draw(gameRules8);
        window.draw(gameRules9);
        window.draw(gameRules10);

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
