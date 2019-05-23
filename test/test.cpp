#include "../src/gamewindow.hpp"
#include "../src/textbox.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace sf;

bool debug = true;

TEST(MovingPuzzle, move_1)
{
    Gamewindow* game;
    game = new Gamewindow(1, 1);
    int result = game->movePuzzle(5, 2);
    delete game;
    game = nullptr;
    ASSERT_EQ(2, result);
}

TEST(MovingPuzzle, move_2)
{
    Gamewindow* game;
    game = new Gamewindow(1, 1);
    int result = game->movePuzzle(2, 5);
    delete game;
    game = nullptr;
    ASSERT_EQ(3, result);
}

TEST(MovingPuzzle, move_3)
{
    Gamewindow* game;
    game = new Gamewindow(1, 1);
    int result = game->movePuzzle(5, 5);
    delete game;
    game = nullptr;
    ASSERT_EQ(4, result);
}

TEST(MovingPuzzle, move_)
{
    Gamewindow* game;
    game = new Gamewindow(1, 1);
    int result = game->movePuzzle(2, 1);
    delete game;
    game = nullptr;
    ASSERT_EQ(0, result);
}

TEST(Textbox, availableCharactersFile)
{
    Textbox box;
    bool result = box.setAvailableCharacters("uncorrect.txt");
    ASSERT_FALSE(result);
}

TEST(Textbox, setString_1)
{
    Textbox box;
    String str("There are too much symbol, that must fail");
    bool result = box.setString(str);
    ASSERT_FALSE(result);
}

int sliceSecondFromString(std::string input);

TEST(RecordSaving, sliceInt_1)
{
    int result = sliceSecondFromString("test:40");
    ASSERT_EQ(40, result);
}

TEST(RecordSaving, sliceInt_2)
{
    int result = sliceSecondFromString("test:error");
    ASSERT_EQ(0, result);
}

TEST(RecordSaving, sliceInt_3)
{
    int result = sliceSecondFromString("test42");
    ASSERT_EQ(0, result);
}

TEST(RecordSaving, sliceInt_4)
{
    int result = sliceSecondFromString("42");
    ASSERT_EQ(0, result);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
