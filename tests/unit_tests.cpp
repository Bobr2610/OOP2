#include <gtest/gtest.h>
#include "decimal.h"
#include <stdexcept>

class DecimalTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(DecimalTest, DefaultConstructor) {
    Decimal dec;
    EXPECT_EQ(dec.toString(), "0");
    EXPECT_FALSE(dec.isEmpty());
}

TEST_F(DecimalTest, ConstructorFromString) {
    Decimal dec("12345");
    EXPECT_EQ(dec.toString(), "12345");
    EXPECT_EQ(dec.getDigitCount(), 5);
}

TEST_F(DecimalTest, ConstructorFromNumber) {
    Decimal dec({6, 7, 8, 9, 0});
    EXPECT_EQ(dec.toString(), "67890");
}

TEST_F(DecimalTest, ConstructorWithSizeAndDefault) {
    Decimal dec(5, 9);
    EXPECT_EQ(dec.toString(), "99999");
    EXPECT_EQ(dec.getDigitCount(), 5);
}

TEST_F(DecimalTest, ConstructorWithSizeZero) {
    Decimal dec(0, 5);
    EXPECT_EQ(dec.toString(), "0");
}

TEST_F(DecimalTest, ConstructorFromInitializerList) {
    Decimal dec({1, 2, 3, 4, 5});
    EXPECT_EQ(dec.toString(), "12345");
    EXPECT_EQ(dec.getDigitCount(), 5);
}
