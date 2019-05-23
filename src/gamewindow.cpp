#include <SFML/Graphics.hpp>
#include "gamewindow.hpp"
#include <vector>

using namespace sf;

static bool win;
static int size;
extern bool debug;

std::string TextboxSymbolsFilepath = "data/availableNameSymbols.txt";
std::string playerRecordsFilepath  = "data/playerRecords.txt";

Gamewindow::Gamewindow(int gameDifficulty, int gameImage)
{
    this->gameDifficulty = gameDifficulty;
    this->gameImage = gameImage;

    font.loadFromFile("texture/font.ttf");

    unsigned int characterSize = 40;

    if (gameDifficulty == 2)
    {
        y_null = 3;
        x_null = 3;
        size = 4;
    }
    else {
        y_null = 2;
        x_null = 2;
        size = 3;
    }

    exitButton.setFont(font);
    exitButton.setCharacterSize(characterSize);
    exitButton.setString("Exit to main menu");
    exitButton.setPosition(20, 520);
    exitButton.setOutlineColor(Color::Red);

    for (Text &z : winInfoText)
    {
        z.setFont(font);
        z.setCharacterSize(24);
    }

    winInfoText[0].setFillColor(Color(120, 255, 40));
    winInfoText[0].setString("YOU WON!   Input nickname:");
    winInfoText[0].setPosition(25, 500);
    winInfoText[1].setFillColor(Color(40, 255, 120));
    winInfoText[1].setString("Your time: ");
    winInfoText[1].setPosition(380, 500);

    gameTimeText.setFont(font);
    gameTimeText.setCharacterSize(characterSize);
    gameTimeText.setPosition(400, 520);

    if (gameImage == 1)
        gameBoardBigTexture.loadFromFile("texture/4x4gameboard.png");
    if (gameImage == 2 && gameDifficulty == 2)
        gameBoardBigTexture.loadFromFile("texture/4x4gameboardImage.png");
    if (gameImage == 2 && gameDifficulty == 1)
    {
        gameBoardBigTexture.loadFromFile("texture/3x3.png");
    }


    for (int i = 0, count = 0; i < size; i++) //заполнение номеров, позиций и текстур
    {
        for (int j = 0; j < size; j++)
        {
            puzzle[i][j].number = puzzle[i][j].position = count + 1;
            puzzle[i][j].sprite.setTexture(gameBoardBigTexture);
            puzzle[i][j].sprite.setTextureRect(IntRect(115 * count++, 0, 115, 115));
        }
    }
    gameNullTexture.loadFromFile("texture/nullImage.png");// текстура пустой области
    puzzle[size-1][size-1].sprite.setTexture(gameNullTexture);
    puzzle[size-1][size-1].sprite.setTextureRect(IntRect(0, 0, 115, 115));


    textbox.setFont(font);
    textbox.setPosition(Vector2f(50, 550));
    textbox.setBoxSize(Vector2f(500, 40));
    if (!textbox.setAvailableCharacters(TextboxSymbolsFilepath))
        exit(1);
    win = false;
    textbox.setFocus(false);
}

int Gamewindow::draw(RenderWindow &window)
{
    window.setTitle("15-Puzzle GAME");
    Color gameBackground(111, 129, 214); // Цвет заднего фона (светло-голубой)
    std::ostringstream gameTimeString;
    Clock gameTime;
    int time = 0;
    std::string nickname = "";

    int mixAmount;
    if (debug)
        mixAmount = 2;
    else
        mixAmount = 800;
    for (int i = 0; i < mixAmount; i++)
        mixPuzzle();

    Event event;

    while(true)
    {
        while (window.pollEvent(event)) // проверка нажатия на крестик (закрыть программу)
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return -1;
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
                return 0;

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
                {
                    if (!win)
                        return 0;
                }

                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (IntRect(puzzle[i][j].sprite.getGlobalBounds()).contains(Mouse::getPosition(window)))
                        {
                            movePuzzle(i, j);
                            if (isPuzzleSolved())
                            {
                                win = true;
                                time = gameTime.getElapsedTime().asSeconds();
                                std::string outputTime = winInfoText[1].getString().toAnsiString();
                                outputTime += std::to_string(time);
                                winInfoText[1].setString(outputTime);
                                textbox.setFocus(true);
                            }
                        }
                    }
                }
            }

            if (win && textbox.isFocus())
            {
                if (event.type == Event::TextEntered)
                {
                    if (event.text.unicode == 8)
                    {
                        textbox.removeChar();
                    }
                    else if (event.text.unicode == 13 && !textbox.isInputEmpty())
                    {
                        nickname = textbox.getInput();
                        savePlayerRecord(nickname, time);
                        return 0;
                    }
                    else if (event.text.unicode < 128)
                    {
                        textbox.addChar((char)event.text.unicode);
                    }
                }
            }
        }

        colorExitButton(window);

        colorPuzzles(Mouse::getPosition(window));
        gameTimeString << (int) gameTime.getElapsedTime().asSeconds();
        gameTimeText.setString("Time: " + gameTimeString.str());
        gameTimeString.str("");

        window.clear(gameBackground);

        if (!win)
        {
            window.draw(exitButton);
            window.draw(gameTimeText);
        }
        else
        {
            window.draw(textbox.drawBox());
            window.draw(textbox.drawText());
            for (Text &z : winInfoText)
                window.draw(z);
        }

        drawBoard(window, gameDifficulty);
        window.display();
    }
}

void Gamewindow::colorExitButton(RenderWindow &window)
{
    if (IntRect(exitButton.getGlobalBounds()).contains(Mouse::getPosition(window)))
    {
        exitButton.setOutlineThickness(2);
    }
    else
    {
        exitButton.setOutlineThickness(0);
    }
}

void Gamewindow::colorPuzzles(Vector2i mousePosition)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (IntRect(puzzle[i][j].sprite.getGlobalBounds()).contains(mousePosition))
            {
                puzzle[i][j].sprite.setColor(Color::Red);
            }
            else
            {
                puzzle[i][j].sprite.setColor(Color::White);
            }
        }
    }
}

void Gamewindow::drawBoard(RenderWindow &window, int gameDifficulty)
{
    int dx = 0, dy = 0;
    if (gameDifficulty == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (puzzle[i][j].position != 0 )
                {
                    dx = 115 * ((puzzle[i][j].position - 1) % 4);
                    dy = 115 * ((puzzle[i][j].position - 1) / 4);
                    puzzle[i][j].sprite.setPosition(70 + dx, 20 + dy);
                    window.draw(puzzle[i][j].sprite);
                }
            }
        }
    }
    else {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (puzzle[i][j].position != 0 )
                {
                    dx = 115 * ((puzzle[i][j].position - 1) % 3);
                    dy = 115 * ((puzzle[i][j].position - 1) / 3);
                    puzzle[i][j].sprite.setPosition(125 + dx, 90 + dy);
                    window.draw(puzzle[i][j].sprite);
                }
            }
        }
    }
}

int Gamewindow::movePuzzle(int i, int j)
{
    if ((i < 0 || i > size - 1)&&(j < 0 || j > size - 1))
    {
        return 4;
    }
    if (i < 0 || i > size - 1)
    {
        return 2;
    }
    if (j < 0 || j > size - 1)
    {
        return 3;
    }
    int y_zero = (puzzle[x_null][y_null].position - 1)/size;
    int x_zero = (puzzle[x_null][y_null].position - 1)%size;

    int y = (puzzle[i][j].position - 1)/size;
    int x = (puzzle[i][j].position - 1)%size;

    if ((abs(y_zero - y)) + (abs(x_zero - x)) == 1)
    {
        int temp = puzzle[x_null][y_null].position;
        puzzle[x_null][y_null].position = puzzle[i][j].position;
        puzzle[i][j].position = temp;
    }
    else return 1;
    return 0;
}

void Gamewindow::mixPuzzle()
{
    int m = rand()%size;
    int k = rand()%size;
    movePuzzle(m,k);
}

bool Gamewindow::isPuzzleSolved()
{
    for (int m = 0; m < size; m++)
    {
        for (int k = 0; k < size; k++)
        {
            if (puzzle[m][k].number != puzzle[m][k].position)
            {
                return false;
            }
        }
    }
    return true;
}

int sliceSecondFromString(std::string input)
{
    std::string newStr;
    bool flag = false;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (flag)
        {
            newStr += input[i];
        }
        if (input[i] == ':')
        {
            flag = true;
        }
    }

    return atoi(newStr.c_str());
}

void Gamewindow::savePlayerRecord(std::string playerName, int seconds)
{
    std::ofstream file;
    std::ifstream checkFile;
    checkFile.open(playerRecordsFilepath, std::ios::in);
    if (!checkFile.is_open())
    {
        file.open(playerRecordsFilepath, std::ios::out);
        file.close();
        checkFile.open(playerRecordsFilepath, std::ios::in);
    }
    std::vector <std::string> fileStrings(0);
    std::string input;

    // считываем все строки
    std::getline(checkFile, input, '\n');
    while (!checkFile.eof())
    {
        fileStrings.push_back(input);
        std::getline(checkFile, input, '\n');
    }
    checkFile.close();

    // если уже достаточно рекордов
    if (fileStrings.size() >= 5)
    {
        int max_index = -1, max = seconds;
        for (int i = 0; i < 5; i++)
        {
            if (sliceSecondFromString(fileStrings[i]) > max)
            {
                max = sliceSecondFromString(fileStrings[i]);
                max_index = i;
            }
        }

        if (max_index != -1)
        {
            fileStrings[max_index] = playerName + ':' + std::to_string(seconds);
        }

        file.open(playerRecordsFilepath, std::ios::out);
        if (!file.is_open())
            exit(1);

        for (auto &x : fileStrings)
        {
            file << x << '\n';
        }
        file.close();
    }
    else
    {
        file.open(playerRecordsFilepath, std::ios::app);
        if (!file.is_open())
            exit(1);
        file << playerName << ":" << (int)seconds << '\n';
        file.close();
    }
}
