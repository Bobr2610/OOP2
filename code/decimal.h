#ifndef DECIMAL_H
#define DECIMAL_H

#include <string>
#include <vector>
#include <initializer_list>
class Decimal
{
private:
    std::vector<unsigned char> digits;
    
    void removeLeadingZeros();
    void normalize();
    Decimal addDigits(const Decimal& other) const;
    Decimal subtractDigits(const Decimal& other) const;
    bool isGreaterThan(const Decimal& other) const;
    bool isLessThan(const Decimal& other) const;
    bool isEqualTo(const Decimal& other) const;

public:
    Decimal();
    Decimal(const size_t& n, unsigned char t = 0);
    Decimal(const std::initializer_list<unsigned char>& t);
    Decimal(const std::string& t);
    Decimal(const Decimal& other);
    Decimal(Decimal&& other) noexcept;
    
    virtual ~Decimal() noexcept;
    
    Decimal& operator=(const Decimal& other);
    Decimal& operator=(Decimal&& other) noexcept;
    
    Decimal add(const Decimal& other) const;
    Decimal subtract(const Decimal& other) const;
    Decimal copy() const;
    
    bool isGreater(const Decimal& other) const;
    bool isLess(const Decimal& other) const;
    bool isEqual(const Decimal& other) const;
    
    Decimal& addAssign(const Decimal& other);
    Decimal& subtractAssign(const Decimal& other);
    
    std::string toString() const;
    size_t getDigitCount() const;
    unsigned char getDigit(size_t index) const;
    bool isEmpty() const;
    
    static Decimal fromString(const std::string& number);
    static Decimal zero();
};

#endif
