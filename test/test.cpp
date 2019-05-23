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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
