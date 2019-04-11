#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "mainmenu.hpp"
#include "settings.hpp"
#include "rules.hpp"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Hello, world!", Style::Close);
    window.setFramerateLimit(30);

    Mainmenu mainmenu;
    Settings settingsmenu;
    Rules rulesmenu;

    int programCode = 0;
    // меньше нуля: завершить программу
    // 0: главное меню
    // 1: начать игру
    // 2: настройки
    // 3: правила игры

    while (programCode >= 0)
    {
        switch (programCode)
        {
        case 0:
            programCode = mainmenu.draw(window);
            break;
        case 1:
            // начать игру
            break;
        case 2:
            programCode = settingsmenu.draw(window);
            break;
        case 3:
            programCode = rulesmenu.draw(window);
            break;
        default:
            programCode = -1;
            break;
        }
    }

    if (window.isOpen()) // лишняя проверка
    {
        window.close();
    }

    return 0;
}
