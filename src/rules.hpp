#ifndef RULES_HPP
#define RULES_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Rules
{
private:
    Font font;

public:
    Rules();
    int draw(RenderWindow &window);
};

#endif
