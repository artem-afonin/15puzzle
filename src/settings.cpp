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

    gameImageUnderline.setSize(Vector2f(60, 5));
    gameImageUnderline.setFillColor(Color::Red);

    exitButton.setFont(font);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit settings");
    exitButton.setPosition(30, 500);
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

        colorExitButton(window);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (IntRect(difficultyOne.getGlobalBounds()).contains(Mouse::getPosition(window)))
            {
                setGameDiffuculty(1);
            }
            else if (IntRect(difficultyTwo.getGlobalBounds()).contains(Mouse::getPosition(window)))
            {
                setGameDiffuculty(2);
            }
            else if (IntRect(gameImageNum.getGlobalBounds()).contains(Mouse::getPosition(window)))
            {
                setGameImage(1);
            }
            else if (IntRect(gameImagePic.getGlobalBounds()).contains(Mouse::getPosition(window)))
            {
                setGameImage(2);
            }
            else if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
            {
                return 0;
            }
        }

        colorDifficultyButtons();
        colorImageButtons();

        window.clear(menuBackground);
        window.draw(settingsPuzzle);
        window.draw(difficultyString);
        window.draw(difficultyOne);
        window.draw(difficultyTwo);
        window.draw(gameImageString);
        window.draw(gameImageNum);
        window.draw(gameImagePic);
        window.draw(gameImageUnderline);
        window.draw(exitButton);
        window.display();
    }
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

void Settings::colorDifficultyButtons()
{
    if (getGameDiffuculty() == 1)
    {
        difficultyOne.setOutlineThickness(2);
        difficultyOne.setOutlineColor(Color::Red);
        difficultyTwo.setOutlineThickness(0);
        difficultyTwo.setOutlineColor(Color::White);
    }
    else
    {
        difficultyOne.setOutlineThickness(0);
        difficultyOne.setOutlineColor(Color::White);
        difficultyTwo.setOutlineThickness(2);
        difficultyTwo.setOutlineColor(Color::Red);
    }
}

void Settings::colorImageButtons()
{
    if (getGameImage() == 1)
    {
        gameImageUnderline.setPosition(312, 180);
    }
    else
    {
        gameImageUnderline.setPosition(485, 180);
    }
}

void Settings::colorExitButton(RenderWindow &window)
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
