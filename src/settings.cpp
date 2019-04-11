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

    unsigned int characterSize = 45;

    difficultyString.setFont(font);
    difficultyString.setCharacterSize(characterSize);
    difficultyString.setString("Difficulty:");
    difficultyString.setPosition(30, 30);

    difficultyOne.setFont(font);
    difficultyOne.setCharacterSize(characterSize);
    difficultyOne.setString("3x3");
    difficultyOne.setPosition(30, 100);

    difficultyTwo.setFont(font);
    difficultyTwo.setCharacterSize(characterSize);
    difficultyTwo.setString("4x4");
    difficultyTwo.setPosition(135, 100);

    gameImageString.setFont(font);
    gameImageString.setCharacterSize(characterSize);
    gameImageString.setString("Board image:");
    gameImageString.setPosition(310, 30);

    gameImageNumTexture.loadFromFile("texture/settingsNumImage.png");
    gameImageNum.setTexture(gameImageNumTexture);
    gameImageNum.setTextureRect(IntRect(11, 11, 43, 43));
    gameImageNum.scale(1.5, 1.5);
    gameImageNum.setPosition(310, 100);

    gameImagePicTexture.loadFromFile("texture/settingsPicImage.png");
    gameImagePic.setTexture(gameImagePicTexture);
    gameImagePic.setPosition(480, 100);
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
                return -1;
            }
        }

        window.clear(menuBackground);
        window.draw(settingsPuzzle);
        window.draw(difficultyString);
        window.draw(difficultyOne);
        window.draw(difficultyTwo);
        window.draw(gameImageString);
        window.draw(gameImageNum);
        window.draw(gameImagePic);
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
