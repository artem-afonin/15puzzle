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

    rulesButton.setFont(font);
    rulesButton.setCharacterSize(menuButtonCharacterSize);
    rulesButton.setString("Rules");
    rulesButton.setPosition(menuButtonX, menuButtonY + 200);

    exitButton.setFont(font);
    exitButton.setCharacterSize(menuButtonCharacterSize);
    exitButton.setString("Exit");
    exitButton.setPosition(menuButtonX, menuButtonY + 300);
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
                return -1;
            }
        }


        menuNum = 0; // обнуляем каждую итерацию
        startGameButton.setFillColor(Color::White); // обнуляем цвет в белый
        settingsButton.setFillColor(Color::White);  // на каждом кадре
        rulesButton.setFillColor(Color::White);
        exitButton.setFillColor(Color::White);

        // ПРОВЕРЯЕМ НАВЕДЕНИЕ НА ПУНКТЫ МЕНЮ //
        if (IntRect(startGameButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
        { // если навелись на кнопку "Start game"
            startGameButton.setFillColor(Color::Red); // подсвечиваем
            menuNum = 1;                              // выставляем пункт меню
        }
        if (IntRect(settingsButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
        { // если навелись на кнопку "Settings"
            settingsButton.setFillColor(Color::Red); // подсвечиваем
            menuNum = 2;                             // выставляем пункт меню
        }
        if (IntRect(rulesButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
        {
            rulesButton.setFillColor(Color::Red);
            menuNum = 3;
        }
        if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
        {
            exitButton.setFillColor(Color::Red);
            menuNum = 4;
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
            case 3:
                return 3;
            case 4:
                return -1;
            }
        }


        window.clear(menuBackground);
        window.draw(linuxLogo);
        window.draw(startGameButton);
        window.draw(settingsButton);
        window.draw(rulesButton);
        window.draw(exitButton);
        window.display();
    }

    return -1; // пока что эта строка недосягаема, пока нету кнопки выхода из игры
}
