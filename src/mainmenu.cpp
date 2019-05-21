#include <SFML/Graphics.hpp>
#include "mainmenu.hpp"

using namespace sf;

Mainmenu::Mainmenu()
{
    font.loadFromFile("texture/font.ttf"); // прогрузка шрифта

    linuxLogoTexture.loadFromFile("texture/mainMenuTux.png");
    linuxLogo.setTexture(linuxLogoTexture);
    linuxLogo.setPosition(25, 400); // прогрузка пингвина слева снизу меню

    menuButtonX = 365; // координата X для кнопок
    menuButtonY = 120; // координата Y для кнопок
    menuButtonCharacterSize = 40; // Размер букв в меню

    startGameButton.setFont(font);
    startGameButton.setCharacterSize(menuButtonCharacterSize);
    startGameButton.setString("Start game");
    startGameButton.setPosition(menuButtonX, menuButtonY);

    settingsButton.setFont(font);
    settingsButton.setCharacterSize(menuButtonCharacterSize);
    settingsButton.setString("Settings");
    settingsButton.setPosition(menuButtonX, menuButtonY + 100);

    rulesButton.setFont(font);
    rulesButton.setCharacterSize(menuButtonCharacterSize);
    rulesButton.setString("Rules");
    rulesButton.setPosition(menuButtonX, menuButtonY + 200);

    exitButton.setFont(font);
    exitButton.setCharacterSize(menuButtonCharacterSize);
    exitButton.setString("Exit");
    exitButton.setPosition(menuButtonX, menuButtonY + 300);

    leaderboardButton.setFont(font);
    leaderboardButton.setCharacterSize(menuButtonCharacterSize);
    leaderboardButton.setString("Leaderboard");
    leaderboardButton.setPosition(20, 20);
}

int Mainmenu::draw(RenderWindow &window)
{
    window.setTitle("Main menu"); // Меняем название окна
    Color menuBackground(111, 129, 214); // Цвет заднего фона меню (светло-голубой)

    Event event; // нужно для выхода из программы по нажатию на крестик

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
                return -1;

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                if (IntRect(startGameButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                    return 1;
                else if (IntRect(settingsButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                    return 2;
                else if (IntRect(rulesButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                    return 3;
                else if (IntRect(leaderboardButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                    return 4;
                else if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                    return -1;
            }
        }

        colorButtons(Mouse::getPosition(window));

        window.clear(menuBackground);
        window.draw(linuxLogo);
        window.draw(startGameButton);
        window.draw(settingsButton);
        window.draw(rulesButton);
        window.draw(exitButton);
        window.draw(leaderboardButton);
        window.display();
    }
}

void Mainmenu::colorButtons(Vector2i mousePosition)
{
    if (IntRect(startGameButton.getGlobalBounds()).contains(mousePosition))
        startGameButton.setFillColor(Color::Red);
    else
        startGameButton.setFillColor(Color::White);

    if (IntRect(settingsButton.getGlobalBounds()).contains(mousePosition))
        settingsButton.setFillColor(Color::Red);
    else
        settingsButton.setFillColor(Color::White);

    if (IntRect(rulesButton.getGlobalBounds()).contains(mousePosition))
        rulesButton.setFillColor(Color::Red);
    else
        rulesButton.setFillColor(Color::White);

    if (IntRect(exitButton.getGlobalBounds()).contains(mousePosition))
        exitButton.setFillColor(Color::Red);
    else
        exitButton.setFillColor(Color::White);

    if (IntRect(leaderboardButton.getGlobalBounds()).contains(mousePosition))
        leaderboardButton.setFillColor(Color::Red);
    else
        leaderboardButton.setFillColor(Color::White);
}
