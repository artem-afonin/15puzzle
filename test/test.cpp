#include "gtest/gtest.h"
#include "../src/textbox.hpp"
#include <iostream>
#include <string>

using namespace sf;

bool debug = true;

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

TEST(Textbox, setString_2)
{
	Textbox box;
	String str("@&normal str&@");
	bool result = box.setString(str);
	ASSERT_TRUE(result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
