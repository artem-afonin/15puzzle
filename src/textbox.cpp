#include "textbox.hpp"

static uint stringMaxLength = 20;

Textbox::Textbox()
{
    focus = false;

    string.clear();

    textCharacterSize = 24;
    text.setFillColor(Color::Black);
    text.setString("");
    text.setCharacterSize(textCharacterSize);

    boxWidth = 200;
    boxHeight = 100;
    boxSize.x = boxWidth;
    boxSize.y = boxHeight;
    box.setSize(boxSize);
    box.setFillColor(Color::White);
}

Textbox::Textbox(float boxWidth, float boxHeight)
{
    Textbox();
    this->boxWidth = boxWidth;
    this->boxHeight = boxHeight;

    boxSize.x = this->boxWidth;
    boxSize.y = this->boxHeight;
    box.setSize(boxSize);
    box.setFillColor(Color::White);
}

String Textbox::getString()
{
    return this->string;
}

bool Textbox::setString(String string)
{
    if (string.getSize() > stringMaxLength)
        return false;
    else
        this->string = string;
    return true;
}

void Textbox::setFont(Font font)
{
    this->text.setFont(font);
}

void Textbox::setCharacterSize(uint textCharacterSize)
{
    this->text.setCharacterSize(textCharacterSize);
}

void Textbox::setBoxSize(Vector2f boxSize)
{
    this->box.setSize(boxSize);
}

void Textbox::setPosition(Vector2f position)
{
    this->box.setPosition(position);
}

Text Textbox::drawText()
{
    return this->text;
}

RectangleShape Textbox::drawBox()
{
    return this->box;
}
