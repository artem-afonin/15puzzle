#include <SFML/Graphics.hpp>
#include "rules.hpp"

using namespace sf;

Rules::Rules()
{
    font.loadFromFile("texture/font.ttf");
}

int Rules::draw(RenderWindow &window)
{
    window.setTitle("Rules");
    Color menuBackground(111, 129, 214);

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
        window.display();
    }
}
