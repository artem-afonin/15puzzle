#ifndef RULES_HPP
#define RULES_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Rules
{
private:
    Font font;

    Text exitButton;

    Text gameRules1;
    Text gameRules2;
    Text gameRules3;
    Text gameRules4;
    Text gameRules5;
    Text gameRules6;
    Text gameRules7;
    Text gameRules8;
    Text gameRules9;
    Text gameRules10;

    void colorExitButton(RenderWindow &window);

public:
    Rules();
    int draw(RenderWindow &window);
};

#endif
