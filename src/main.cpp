#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "mainmenu.hpp"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Hello, world!", Style::Close);
    Mainmenu mainmenu;
    window.setFramerateLimit(30);

    int programCode = 0;
    // 0 завершить программу
    // 1 начать игру
    // 2 настройки
    // 3 правила игры

    programCode = mainmenu.draw(window);

    if (window.isOpen()) // лишняя проверка
    {
        window.close();
    }
    return 0;
}
