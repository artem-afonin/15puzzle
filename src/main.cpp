#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Hello, world!", Style::Close);

    CircleShape circle(300);
    circle.setFillColor(Color::Blue);

    while (window.isOpen())
    {
        Event e;
        while(window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
