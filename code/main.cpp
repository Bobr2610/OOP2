#include <iostream>
#include <string>
#include "decimal.h"

void demonstrateDecimal() {
    std::cout << "=== Decimal Class Demonstration ===" << std::endl;
    
    // Test constructors
    std::cout << "\n1. Testing Decimal constructors:" << std::endl;
    
    // Default constructor
    Decimal dec1;
    std::cout << "Default constructor: " << dec1.toString() << std::endl;
    
    // Constructor from string
    Decimal dec2("12345");
    std::cout << "Constructor from string '12345': " << dec2.toString() << std::endl;
    
    // Constructor from initializer list
    Decimal dec3({6, 7, 8, 9, 0});
    std::cout << "Constructor from initializer list {6,7,8,9,0}: " << dec3.toString() << std::endl;
    
    // Constructor with size and default value
    Decimal dec3b(5, 9);
    std::cout << "Constructor with size 5 and default value 9: " << dec3b.toString() << std::endl;
    
    // Copy constructor
    Decimal dec4(dec2);
    std::cout << "Copy constructor: " << dec4.toString() << std::endl;
    
    // Test arithmetic operations
    std::cout << "\n2. Testing arithmetic operations:" << std::endl;
    Decimal dec5("12345");
    Decimal dec6("67890");
    Decimal sum = dec5.add(dec6);
    Decimal diff = dec6.subtract(dec5);
    std::cout << "Decimal 1: " << dec5.toString() << std::endl;
    std::cout << "Decimal 2: " << dec6.toString() << std::endl;
    std::cout << "Sum: " << sum.toString() << std::endl;
    std::cout << "Difference: " << diff.toString() << std::endl;
    
    // Test comparison operations
    std::cout << "\n3. Testing comparison operations:" << std::endl;
    Decimal dec7("12345");
    Decimal dec8("67890");
    std::cout << "Decimal 1: " << dec7.toString() << std::endl;
    std::cout << "Decimal 2: " << dec8.toString() << std::endl;
    std::cout << "Decimal 1 > Decimal 2: " << dec7.isGreater(dec8) << std::endl;
    std::cout << "Decimal 1 < Decimal 2: " << dec7.isLess(dec8) << std::endl;
    std::cout << "Decimal 1 == Decimal 1: " << dec7.isEqual(dec7) << std::endl;
    
    // Test assignment operations
    std::cout << "\n4. Testing assignment operations:" << std::endl;
    Decimal dec9("1000");
    Decimal dec10("500");
    std::cout << "Before addAssign: " << dec9.toString() << std::endl;
    dec9.addAssign(dec10);
    std::cout << "After addAssign: " << dec9.toString() << std::endl;
    
    // Test large numbers
    std::cout << "\n5. Testing large numbers:" << std::endl;
    Decimal dec11("999999999999999999");
    Decimal dec12("1");
    Decimal largeSum = dec11.add(dec12);
    std::cout << "Large number: " << dec11.toString() << std::endl;
    std::cout << "Large number + 1: " << largeSum.toString() << std::endl;
    
    // Test edge cases
    std::cout << "\n6. Testing edge cases:" << std::endl;
    Decimal dec13("0");
    Decimal dec14("0");
    Decimal zeroSum = dec13.add(dec14);
    std::cout << "Zero + Zero: " << zeroSum.toString() << std::endl;
    
    Decimal dec15("1000");
    Decimal dec16("999");
    Decimal edgeDiff = dec15.subtract(dec16);
    std::cout << "1000 - 999: " << edgeDiff.toString() << std::endl;
}

void testExceptionHandling() {
    std::cout << "\n=== Exception Handling Demonstration ===" << std::endl;
    
    try {
        // Test invalid decimal string
        std::cout << "\n1. Testing invalid decimal string:" << std::endl;
        Decimal invalid("12a34");
        std::cout << "This should not be printed" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        // Test decimal digit out of range
        std::cout << "\n2. Testing decimal digit out of range:" << std::endl;
        Decimal dec("123");
        std::cout << "Decimal: " << dec.toString() << std::endl;
        std::cout << "Accessing digit 10: " << dec.getDigit(10) << std::endl;
        std::cout << "This should not be printed" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        // Test subtraction of larger number
        std::cout << "\n3. Testing subtraction of larger number:" << std::endl;
        Decimal small("100");
        Decimal large("200");
        Decimal result = small.subtract(large);
        std::cout << "This should not be printed" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "OOP Lab 2 - Decimal Class Implementation" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    demonstrateDecimal();
    testExceptionHandling();
    
    std::cout << "\n=== Program completed successfully ===" << std::endl;
    return 0;
}
