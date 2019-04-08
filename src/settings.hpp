#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Settings
{
private:
    Font font;

    int gameDifficulty; // 1 - 3x3; 2 - 4x4; 3 - 5x5;
    int gameImage; // 1 - цифры; 2 - картинка1; 3 - картинка2;

    Texture settingsPuzzleTexture;
    Sprite settingsPuzzle;
public:
    Settings();

    int getGameDiffuculty();
    void setGameDiffuculty(int difficulty);

    int getGameImage();
    void setGameImage(int imageNumber);

    int draw(RenderWindow &window);
};

#endif // SETTINGS_HPP
