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

    //МЕТОДЫ
    void fillLeaderboardText();
public:
    Leaderboard();

    int draw(RenderWindow &window);
};

#endif // LEADERBOARD_HPP
