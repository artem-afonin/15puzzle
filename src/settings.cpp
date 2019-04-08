#include <SFML/Graphics.hpp>
#include "settings.hpp"

using namespace sf;

Settings::Settings()
{
    font.loadFromFile("texture/font.ttf"); // прогрузка шрифта

    settingsPuzzleTexture.loadFromFile("texture/settingsImage.png");
    settingsPuzzle.setTexture(settingsPuzzleTexture);
    settingsPuzzle.setPosition(280, 335);

    setGameDiffuculty(2); // 4x4
    setGameImage(1); // цифры
}

int Settings::draw(RenderWindow &window)
{
    window.setTitle("Settings");
    Color menuBackground(111, 129, 214); // Цвет заднего фона (светло-голубой)

    Event event;

    while(true)
    {
        while (window.pollEvent(event)) // проверка нажатия на крестик (закрыть программу)
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        window.clear(menuBackground);
        window.draw(settingsPuzzle);
        window.display();
    }

    return -1; // пока что недосягаем
}


void Settings::setGameDiffuculty(int difficulty)
{
    gameDifficulty = difficulty;
}

int Settings::getGameDiffuculty()
{
    return gameDifficulty;
}


void Settings::setGameImage(int imageNumber)
{
    gameImage = imageNumber;
}

int Settings::getGameImage()
{
    return gameImage;
}
