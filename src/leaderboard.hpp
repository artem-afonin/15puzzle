#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Leaderboard
{
private:
    // ПЕРЕМЕННЫЕ
    Font font;
    Text exitButton;
    Text leaderboardText[5];
    Text resetButton;

    //МЕТОДЫ
    void fillLeaderboardText();
    void colorButtons(Vector2i mousePosition);
public:
    Leaderboard();

    int draw(RenderWindow &window);
};

#endif // LEADERBOARD_HPP
