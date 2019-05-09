#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Mainmenu
{
private:
    Font font;

    Texture linuxLogoTexture;
    Sprite linuxLogo;

    Text startGameButton;
    Text settingsButton;
    Text rulesButton;
    Text exitButton;

    int menuButtonX;
    int menuButtonY;
    unsigned int menuButtonCharacterSize;

    void colorButtons(Vector2i mousePosition);
public:
    Mainmenu();
    int draw(RenderWindow &window);
};

#endif // MAINMENU_HPP
