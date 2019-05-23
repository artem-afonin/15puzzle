#include "gtest/gtest.h"

bool debug = true;

TEST(PrimaryTest, FirstPrimaryTest)
{
    EXPECT_EQ (18.0, 18.0);
}

TEST(PrimaryTest, SecondPrimaryTest)
{
    EXPECT_EQ (25.4, 25.4);
}

TEST(PrimaryTest, ThirdPrimaryTest)
{
    EXPECT_EQ (50.3321, 50.3321);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
