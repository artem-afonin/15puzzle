#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "mainmenu.hpp"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Hello, world!", Style::Close);
    Mainmenu mainmenu;
    mainmenu.draw(window);

    if (window.isOpen())
    {
        window.close();
    }
    return 0;
}
