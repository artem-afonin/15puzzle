#ifndef RULES_HPP
#define RULES_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Rules
{
private:
    Font font;

    Text exitButton;

    Text gameRules[10];

    void colorExitButton(RenderWindow &window);

public:
    Rules();
    int draw(RenderWindow &window);
};

#endif
