#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Settings
{
private:
    int gameDifficulty;
    int gameImage;
public:
    Settings();

    int getGameDiffuculty();
    void setGameDiffuculty(int difficulty);

    int getGameImage();
    void setGameImage(int imageNumber);

    int draw(RenderWindow &window);
};

#endif // SETTINGS_HPP
