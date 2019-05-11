#include "textbox.hpp"
#include <iostream>

static uint stringMaxLength = 15;

Textbox::Textbox()
{
    focus = false;

    string.clear();

    textCharacterSize = 24;
    text.setFillColor(Color::Black);
    text.setString(string);
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

void Textbox::setFont(Font &font)
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
    this->text.setCharacterSize((unsigned int)boxSize.y);
}

void Textbox::setPosition(Vector2f position)
{
    this->box.setPosition(position);
    this->text.setPosition(position.x, position.y - 5);
}

void Textbox::setFocus(bool focus)
{
    this->focus = focus;
}

bool Textbox::isFocus()
{
    return this->focus;
}

bool Textbox::setAvailableCharacters(std::string filePath)
{
    availableCharacters = new char[64];
    std::ifstream file;
    file.open(filePath);
    if (!file.is_open())
        return false;
    for (int i = 0; i < 64; i++)
        file >> availableCharacters[i];
    file.close();
    return true;
}

void Textbox::addChar(char letter)
{
    bool flag = false;
    for (int i = 0; i < 64; i++)
    {
        if (letter == availableCharacters[i])
            flag = true;
    }

    if (flag && this->string.getSize() < stringMaxLength)
    {
        this->string += letter;
    }

    this->text.setString(string);
}

void Textbox::removeChar()
{
    if (!this->string.isEmpty())
        this->string.erase(this->string.getSize() - 1);

    this->text.setString(string);
}

bool Textbox::isInputEmpty()
{
    if (this->string.getSize() > 0)
        return false;
    return true;
}

std::string Textbox::getInput()
{
    return this->string.toAnsiString();
}

Text Textbox::drawText()
{
    return this->text;
}

RectangleShape Textbox::drawBox()
{
    return this->box;
}

Textbox::~Textbox()
{
    delete availableCharacters;
    availableCharacters = NULL;
}
