#include <SFML/Graphics.hpp>
#include "mainmenu.hpp"

using namespace sf;

Mainmenu::Mainmenu()
{
    font.loadFromFile("texture/font.ttf"); // прогрузка шрифта

    linuxLogoTexture.loadFromFile("texture/mainMenuTux.png");
    linuxLogo.setTexture(linuxLogoTexture);
    linuxLogo.setPosition(25, 400); // прогрузка пингвина слева снизу меню

    menuButtonX = 365; // координата X для кнопок
    menuButtonY = 120; // координата Y для кнопок
    menuButtonCharacterSize = 40; // Размер букв в меню

    startGameButton.setFont(font);
    startGameButton.setCharacterSize(menuButtonCharacterSize);
    startGameButton.setString("Start game");
    startGameButton.setPosition(menuButtonX, menuButtonY);

    settingsButton.setFont(font);
    settingsButton.setCharacterSize(menuButtonCharacterSize);
    settingsButton.setString("Settings");
    settingsButton.setPosition(menuButtonX, menuButtonY + 100);
}

int Mainmenu::draw(RenderWindow &window)
{
    window.setTitle("Main menu"); // Меняем название окна
    Color menuBackground(111, 129, 214); // Цвет заднего фона меню (светло-голубой)
    int menuNum = 0; // выбранный пункт меню

    Event event; // нужно для выхода из программы по нажатию на крестик

    while(true)
    {
        while (window.pollEvent(event)) // проверка нажатия на крестик (закрыть программу)
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return 0;
            }
        }


        menuNum = 0; // обнуляем каждую итерацию
        startGameButton.setFillColor(Color::White); // обнуляем цвет в белый
        settingsButton.setFillColor(Color::White);  // на каждом кадре

        // ПРОВЕРЯЕМ НАВЕДЕНИЕ НА ПУНКТЫ МЕНЮ //
        if (IntRect(menuButtonX, menuButtonY + 5, 195, 40).contains(Mouse::getPosition(window)))
        { // если навелись на кнопку "Start game"
            startGameButton.setFillColor(Color::Red); // подсвечиваем
            menuNum = 1;                              // выставляем пункт меню
        }
        if (IntRect(menuButtonX, menuButtonY + 105, 150, 40).contains(Mouse::getPosition(window)))
        { // если навелись на кнопку "Settings"
            settingsButton.setFillColor(Color::Red); // подсвечиваем
            menuNum = 2;                             // выставляем пункт меню
        }


        // ПРОВЕРЯЕМ НАЖАТИЕ КЛАВИШИ //
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            switch (menuNum) // если при нажатии наведено на пункт меню
            {
            case 1:
                return 1;
            case 2:
                return 2;
            }
        }


        window.clear(menuBackground);
        window.draw(linuxLogo);
        window.draw(startGameButton);
        window.draw(settingsButton);        
        window.display();
    }

    return 0; // пока что эта строка недосягаема, пока нету кнопки выхода из игры
}
