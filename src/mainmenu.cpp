#include <SFML/Graphics.hpp>
#include "mainmenu.hpp"

using namespace sf;

Mainmenu::Mainmenu()
{
    font.loadFromFile("texture/font.ttf");

    linuxLogoTexture.loadFromFile("texture/mainMenuTux.png");
    linuxLogo.setTexture(linuxLogoTexture);

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
    window.setFramerateLimit(10);
    window.setTitle("Main menu");
    Color menuBackground(111, 129, 214);
    bool isMenu = true;

    while(isMenu)
    {
        Event event;
        if (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                isMenu = false;
                window.close();
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
