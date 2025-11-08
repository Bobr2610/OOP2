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

TEST_F(DecimalTest, ConstructorFromInitializerListSingleDigit) {
    Decimal dec({7});
    EXPECT_EQ(dec.toString(), "7");
    EXPECT_EQ(dec.getDigitCount(), 1);
}

TEST_F(DecimalTest, ConstructorFromInitializerListInvalidDigit) {
    EXPECT_THROW(Decimal({1, 2, 10, 4}), std::invalid_argument);
    EXPECT_THROW(Decimal({15}), std::invalid_argument);
}

TEST_F(DecimalTest, ConstructorWithSizeInvalidDigit) {
    EXPECT_THROW(Decimal(5, 10), std::invalid_argument);
    EXPECT_THROW(Decimal(3, 15), std::invalid_argument);
}

TEST_F(DecimalTest, ConstructorFromStringWithLeadingZeros) {
    Decimal dec("000123");
    EXPECT_EQ(dec.toString(), "123");
}

TEST_F(DecimalTest, ConstructorFromEmptyString) {
    Decimal dec("");
    EXPECT_EQ(dec.toString(), "0");
}

TEST_F(DecimalTest, ConstructorFromZeroString) {
    Decimal dec("000");
    EXPECT_EQ(dec.toString(), "0");
}

TEST_F(DecimalTest, ConstructorFromInvalidString) {
    EXPECT_THROW(Decimal("12a34"), std::invalid_argument);
    EXPECT_THROW(Decimal("abc"), std::invalid_argument);
    EXPECT_THROW(Decimal("12-34"), std::invalid_argument);
}

TEST_F(DecimalTest, CopyConstructor) {
    Decimal original("12345");
    Decimal copy(original);
    EXPECT_EQ(copy.toString(), original.toString());
    EXPECT_TRUE(copy.isEqual(original));
}

TEST_F(DecimalTest, MoveConstructor) {
    Decimal original("67890");
    Decimal moved(std::move(original));
    EXPECT_EQ(moved.toString(), "67890");
    EXPECT_EQ(original.toString(), "0");
}

TEST_F(DecimalTest, AssignmentOperator) {
    Decimal dec1("12345");
    Decimal dec2;
    dec2 = dec1;
    EXPECT_EQ(dec2.toString(), dec1.toString());
    EXPECT_TRUE(dec2.isEqual(dec1));
}

TEST_F(DecimalTest, MoveAssignmentOperator) {
    Decimal dec1("67890");
    Decimal dec2;
    dec2 = std::move(dec1);
    EXPECT_EQ(dec2.toString(), "67890");
    EXPECT_EQ(dec1.toString(), "0");
}

TEST_F(DecimalTest, AdditionOperation) {
    Decimal dec1("12345");
    Decimal dec2("67890");
    Decimal sum = dec1.add(dec2);
    EXPECT_EQ(sum.toString(), "80235");
}

TEST_F(DecimalTest, AdditionWithCarry) {
    Decimal dec1("999");
    Decimal dec2("1");
    Decimal sum = dec1.add(dec2);
    EXPECT_EQ(sum.toString(), "1000");
}

TEST_F(DecimalTest, SubtractionOperation) {
    Decimal dec1("1000");
    Decimal dec2("999");
    Decimal diff = dec1.subtract(dec2);
    EXPECT_EQ(diff.toString(), "1");
}

TEST_F(DecimalTest, SubtractionLargerFromSmaller) {
    Decimal dec1("100");
    Decimal dec2("200");
    EXPECT_THROW(dec1.subtract(dec2), std::invalid_argument);
}

TEST_F(DecimalTest, CopyOperation) {
    Decimal original("12345");
    Decimal copy = original.copy();
    EXPECT_EQ(copy.toString(), original.toString());
    EXPECT_TRUE(copy.isEqual(original));
}

TEST_F(DecimalTest, ComparisonOperations) {
    Decimal dec1("12345");
    Decimal dec2("67890");
    Decimal dec3("12345");
    
    EXPECT_TRUE(dec2.isGreater(dec1));
    EXPECT_TRUE(dec1.isLess(dec2));
    EXPECT_TRUE(dec1.isEqual(dec3));
    EXPECT_FALSE(dec1.isGreater(dec2));
    EXPECT_FALSE(dec1.isLess(dec3));
}

TEST_F(DecimalTest, ComparisonWithDifferentLengths) {
    Decimal dec1("123");
    Decimal dec2("12345");
    
    EXPECT_TRUE(dec2.isGreater(dec1));
    EXPECT_TRUE(dec1.isLess(dec2));
}

TEST_F(DecimalTest, AssignmentArithmeticOperations) {
    Decimal dec1("1000");
    Decimal dec2("500");
    Decimal original = dec1;
    
    dec1.addAssign(dec2);
    EXPECT_EQ(dec1.toString(), "1500");
    
    dec1.subtractAssign(dec2);
    EXPECT_EQ(dec1.toString(), original.toString());
}

TEST_F(DecimalTest, LargeNumbers) {
    Decimal dec1("999999999999999999");
    Decimal dec2("1");
    Decimal sum = dec1.add(dec2);
    EXPECT_EQ(sum.toString(), "1000000000000000000");
}

TEST_F(DecimalTest, ZeroOperations) {
    Decimal zero1("0");
    Decimal zero2("0");
    Decimal sum = zero1.add(zero2);
    Decimal diff = zero1.subtract(zero2);
    
    EXPECT_EQ(sum.toString(), "0");
    EXPECT_EQ(diff.toString(), "0");
}

TEST_F(DecimalTest, GetDigit) {
    Decimal dec("12345");
    EXPECT_EQ(dec.getDigit(0), 5); // Least significant digit
    EXPECT_EQ(dec.getDigit(1), 4);
    EXPECT_EQ(dec.getDigit(4), 1); // Most significant digit
}

TEST_F(DecimalTest, GetDigitOutOfRange) {
    Decimal dec("123");
    EXPECT_THROW(dec.getDigit(5), std::out_of_range);
}

TEST_F(DecimalTest, StaticFactoryMethods) {
    Decimal dec1 = Decimal::fromString("12345");
    Decimal zero = Decimal::zero();
    
    EXPECT_EQ(dec1.toString(), "12345");
    EXPECT_EQ(zero.toString(), "0");
}

TEST_F(DecimalTest, Immutability) {
    Decimal dec1("1000");
    Decimal dec2("500");
    Decimal original = dec1;
    
    // Operations should return new objects, not modify originals
    Decimal sum = dec1.add(dec2);
    Decimal diff = dec1.subtract(dec2);
    
    EXPECT_EQ(dec1.toString(), original.toString());
    EXPECT_EQ(sum.toString(), "1500");
    EXPECT_EQ(diff.toString(), "500");
}

TEST_F(DecimalTest, EdgeCases) {
    // Test with very long numbers
    std::string longNumber = "123456789012345678901234567890";
    Decimal longDec(longNumber);
    EXPECT_EQ(longDec.toString(), longNumber);
    
    // Test with single digit
    Decimal single("7");
    EXPECT_EQ(single.toString(), "7");
    EXPECT_EQ(single.getDigitCount(), 1);
    EXPECT_EQ(single.getDigit(0), 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
