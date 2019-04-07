#include <SFML/Graphics.hpp>
#include "mainmenu.hpp"

using namespace sf;

Mainmenu::Mainmenu()
{
    font.loadFromFile("texture/font.ttf");

    linuxLogoTexture.loadFromFile("texture/mainMenuTux.png");
    linuxLogo.setTexture(linuxLogoTexture);
    linuxLogo.setPosition(25, 400);

    menuButtonX = 365;
    menuButtonY = 120;
    menuButtonCharacterSize = 40;
    startGameButton.setFont(font);
    startGameButton.setCharacterSize(menuButtonCharacterSize);
    startGameButton.setString("Start game");
    startGameButton.setPosition(menuButtonX, menuButtonY);

    settingsButton.setFont(font);
    settingsButton.setCharacterSize(menuButtonCharacterSize);
    settingsButton.setString("Settings");
    settingsButton.setPosition(menuButtonX, menuButtonY + 100);
}

int Mainmenu::draw(RenderWindow &window)
{
    window.setTitle("Main menu");
    Color menuBackground(111, 129, 214);
    int menuNum = 0;

    Event event;

    while(true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        menuNum = 0;
        startGameButton.setFillColor(Color::White);
        settingsButton.setFillColor(Color::White);

        // ПРОВЕРЯЕМ НАВЕДЕНИЕ НА ПУНКТЫ МЕНЮ //
        if (IntRect(menuButtonX, menuButtonY + 5, 195, 40).contains(Mouse::getPosition(window)))
        { // если навелись на кнопку "Start game"
            startGameButton.setFillColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(menuButtonX, menuButtonY + 105, 150, 40).contains(Mouse::getPosition(window)))
        { // если навелись на кнопку "Settings"
            settingsButton.setFillColor(Color::Red);
            menuNum = 2;
        }


        // ПРОВЕРЯЕМ НАЖАТИЕ КЛАВИШИ //
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            switch (menuNum)
            {
            case 1:
                return 1;
            case 2:
                return 2;
            }
        }


        window.clear(menuBackground);
        window.draw(linuxLogo);
        window.draw(startGameButton);
        window.draw(settingsButton);        
        window.display();
    }

    return 0;
}
