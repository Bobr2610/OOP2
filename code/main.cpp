#include <iostream>
#include <string>
#include "decimal.h"

void demonstrateDecimal() {
    std::cout << "Constructors:" << std::endl;
    
    Decimal dec1;
    std::cout << "Default: " << dec1.toString() << std::endl;
    
    Decimal dec2("12345");
    std::cout << "String: " << dec2.toString() << std::endl;
    
    Decimal dec3({6, 7, 8, 9, 0});
    std::cout << "List: " << dec3.toString() << std::endl;
    
    Decimal dec3b(5, 9);
    std::cout << "Size: " << dec3b.toString() << std::endl;
    
    Decimal dec4(dec2);
    std::cout << "Copy: " << dec4.toString() << std::endl;
    
    std::cout << "\nArithmetic:" << std::endl;
    Decimal dec5("12345");
    Decimal dec6("67890");
    Decimal sum = dec5.add(dec6);
    Decimal diff = dec6.subtract(dec5);
    std::cout << dec5.toString() << " + " << dec6.toString() << " = " << sum.toString() << std::endl;
    std::cout << dec6.toString() << " - " << dec5.toString() << " = " << diff.toString() << std::endl;
    
    std::cout << "\nComparison:" << std::endl;
    Decimal dec7("12345");
    Decimal dec8("67890");
    std::cout << dec7.toString() << " > " << dec8.toString() << ": " << dec7.isGreater(dec8) << std::endl;
    std::cout << dec7.toString() << " < " << dec8.toString() << ": " << dec7.isLess(dec8) << std::endl;
    std::cout << dec7.toString() << " == " << dec7.toString() << ": " << dec7.isEqual(dec7) << std::endl;
    
    std::cout << "\nAssignment:" << std::endl;
    Decimal dec9("1000");
    Decimal dec10("500");
    std::cout << "Before: " << dec9.toString() << std::endl;
    dec9.addAssign(dec10);
    std::cout << "After: " << dec9.toString() << std::endl;
    
    std::cout << "\nLarge numbers:" << std::endl;
    Decimal dec11("999999999999999999");
    Decimal dec12("1");
    Decimal largeSum = dec11.add(dec12);
    std::cout << dec11.toString() << " + 1 = " << largeSum.toString() << std::endl;
    
    std::cout << "\nEdge cases:" << std::endl;
    Decimal dec13("0");
    Decimal dec14("0");
    Decimal zeroSum = dec13.add(dec14);
    std::cout << "0 + 0 = " << zeroSum.toString() << std::endl;
    
    Decimal dec15("1000");
    Decimal dec16("999");
    Decimal edgeDiff = dec15.subtract(dec16);
    std::cout << "1000 - 999 = " << edgeDiff.toString() << std::endl;
}

void testExceptionHandling() {
    std::cout << "\nExceptions:" << std::endl;
    
    try {
        Decimal invalid("12a34");
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid string: " << e.what() << std::endl;
    }
    
    try {
        Decimal dec("123");
        dec.getDigit(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }
    
    try {
        Decimal small("100");
        Decimal large("200");
        small.subtract(large);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid subtraction: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "OOP Lab 2" << std::endl;
    
    demonstrateDecimal();
    testExceptionHandling();
    
    return 0;
}
