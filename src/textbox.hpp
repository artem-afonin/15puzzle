#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;
using namespace std;

typedef unsigned int uint;

class Textbox
{
private:
    // АТРИБУТЫ
    bool focus; // фокус на текстбоксе?
    String string; // сам текст
    Text text; // графическое отображение текста
    RectangleShape box; // белый прямоугольник-фон

    float boxWidth;
    float boxHeight;
    Vector2f boxSize;
    uint textCharacterSize;
    char* availableCharacters;


    // МЕТОДЫ

public:
    Textbox();
    Textbox(float boxWidth, float boxHeight);
    ~Textbox();

    String getString();

    bool setString(String string);
    void setFont(Font &font);
    void setCharacterSize(uint textCharacterSize);
    void setBoxSize(Vector2f boxSize);
    void setPosition(Vector2f position);
    void setFocus(bool focus);
    bool setAvailableCharacters(std::string filePath); // допустимые буквы находятся в файле

    Text drawText();
    RectangleShape drawBox();
};

#endif // TEXTBOX_HPP
