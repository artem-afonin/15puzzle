#include "leaderboard.hpp"

Leaderboard::Leaderboard()
{
    font.loadFromFile("texture/font.ttf");

    unsigned int characterSize = 40;
    exitButton.setFont(font);
    exitButton.setOutlineColor(Color::Red);
    exitButton.setOutlineThickness(0.f);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit to mainmenu");
}

int Leaderboard::draw(RenderWindow &window)
{
    window.setTitle("Leaderboard");
    Color gameBackground(111, 129, 214); // Цвет заднего фона (светло-голубой)

    Event event;
    while (true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return -1;
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
                return 0;
        }

        window.clear(gameBackground);

        window.display();
    }
}
