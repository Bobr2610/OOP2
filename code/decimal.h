#ifndef DECIMAL_H
#define DECIMAL_H

#include <string>
#include <vector>
#include <initializer_list>
class Decimal
{
private:
    std::vector<unsigned char> digits; // Each element is a decimal digit (0-9)
    // Least significant digit (units) is at index 0
    
    // Helper methods
    void removeLeadingZeros();
    void normalize();
    Decimal addDigits(const Decimal& other) const;
    Decimal subtractDigits(const Decimal& other) const;
    bool isGreaterThan(const Decimal& other) const;
    bool isLessThan(const Decimal& other) const;
    bool isEqualTo(const Decimal& other) const;

public:
    // Constructors
    Decimal(); // Default constructor (creates 0)
    Decimal(const size_t& n, unsigned char t = 0); // Constructor with size and default value
    Decimal(const std::initializer_list<unsigned char>& t); // Constructor from initializer list
    Decimal(const std::string& t); // Constructor from string
    Decimal(const Decimal& other); // Copy constructor
    Decimal(Decimal&& other) noexcept; // Move constructor
    
    // Destructor
    virtual ~Decimal() noexcept;
    
    // Assignment operators
    Decimal& operator=(const Decimal& other);
    Decimal& operator=(Decimal&& other) noexcept;
    
    // Arithmetic operations (return new objects - immutable)
    Decimal add(const Decimal& other) const;
    Decimal subtract(const Decimal& other) const;
    Decimal copy() const;
    
    // Comparison operations
    bool isGreater(const Decimal& other) const;
    bool isLess(const Decimal& other) const;
    bool isEqual(const Decimal& other) const;
    
    // Assignment arithmetic operations (as class methods)
    Decimal& addAssign(const Decimal& other);
    Decimal& subtractAssign(const Decimal& other);
    
    // Utility methods
    std::string toString() const;
    size_t getDigitCount() const;
    unsigned char getDigit(size_t index) const;
    bool isEmpty() const;
    
    // Static factory methods
    static Decimal fromString(const std::string& number);
    static Decimal zero();
};

#endif // DECIMAL_H
