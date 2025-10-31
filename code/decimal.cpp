#include "decimal.h"
#include <algorithm>
#include <stdexcept>

// Default constructor (creates 0)
Decimal::Decimal() : digits(1, 0) {}

// Constructor with size and default value
Decimal::Decimal(const size_t& n, unsigned char t) {
    if (n == 0) {
        digits.push_back(0);
        return;
    }
    
    // Validate digit value
    if (t > 9) {
        throw std::invalid_argument("Invalid decimal digit: must be 0-9");
    }
    
    digits.resize(n, t);
    normalize();
}

// Constructor from initializer list
Decimal::Decimal(const std::initializer_list<unsigned char>& t) {
    if (t.size() == 0) {
        digits.push_back(0);
        return;
    }
    
    // Validate all digits
    for (unsigned char digit : t) {
        if (digit > 9) {
            throw std::invalid_argument("Invalid decimal digit: must be 0-9");
        }
    }
    
    // Convert initializer list to digits (least significant digit first)
    // The initializer list is assumed to be in normal order (most significant first)
    for (auto it = t.end(); it != t.begin();) {
        --it;
        digits.push_back(*it);
    }
    
    normalize();
}

// Constructor from string
Decimal::Decimal(const std::string& t) {
    if (t.empty()) {
        digits.push_back(0);
        return;
    }
    
    // Remove leading zeros
    size_t start = 0;
    while (start < t.length() && t[start] == '0') {
        start++;
    }
    
    if (start == t.length()) {
        digits.push_back(0);
        return;
    }
    
    // Validate that all characters are digits
    for (size_t i = start; i < t.length(); ++i) {
        if (t[i] < '0' || t[i] > '9') {
            throw std::invalid_argument("Invalid decimal string: contains non-digit characters");
        }
    }
    
    // Convert string to digits (least significant digit first)
    for (int i = static_cast<int>(t.length()) - 1; i >= static_cast<int>(start); --i) {
        digits.push_back(static_cast<unsigned char>(t[i] - '0'));
    }
}

// Copy constructor
Decimal::Decimal(const Decimal& other) : digits(other.digits) {}

// Move constructor
Decimal::Decimal(Decimal&& other) noexcept : digits(std::move(other.digits)) {
    other.digits = {0};
}

// Destructor
Decimal::~Decimal() noexcept {}

// Assignment operator
Decimal& Decimal::operator=(const Decimal& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

// Move assignment operator
Decimal& Decimal::operator=(Decimal&& other) noexcept {
    if (this != &other) {
        digits = std::move(other.digits);
        other.digits = {0};
    }
    return *this;
}

// Remove leading zeros
void Decimal::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}

// Normalize the number
void Decimal::normalize() {
    removeLeadingZeros();
    if (digits.empty()) {
        digits.push_back(0);
    }
}

// Add digits
Decimal Decimal::addDigits(const Decimal& other) const {
    Decimal result;
    result.digits.clear();
    
    size_t maxSize = std::max(digits.size(), other.digits.size());
    unsigned char carry = 0;
    
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    
    if (carry > 0) {
        result.digits.push_back(carry);
    }
    
    result.normalize();
    return result;
}

// Subtract digits
Decimal Decimal::subtractDigits(const Decimal& other) const {
    if (isLessThan(other)) {
        throw std::invalid_argument("Cannot subtract larger number from smaller number");
    }
    
    Decimal result;
    result.digits.clear();
    
    unsigned char borrow = 0;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char minuend = (i < digits.size()) ? digits[i] : 0;
        unsigned char subtrahend = (i < other.digits.size()) ? other.digits[i] : 0;
        
        if (minuend < subtrahend + borrow) {
            minuend += 10;
            result.digits.push_back(minuend - subtrahend - borrow);
            borrow = 1;
        } else {
            result.digits.push_back(minuend - subtrahend - borrow);
            borrow = 0;
        }
    }
    
    result.normalize();
    return result;
}

// Check if greater than
bool Decimal::isGreaterThan(const Decimal& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() > other.digits.size();
    }
    
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] > other.digits[i];
        }
    }
    
    return false; // Equal
}

// Check if less than
bool Decimal::isLessThan(const Decimal& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    
    return false; // Equal
}

// Check if equal
bool Decimal::isEqualTo(const Decimal& other) const {
    return digits == other.digits;
}

// Addition operation
Decimal Decimal::add(const Decimal& other) const {
    return addDigits(other);
}

// Subtraction operation
Decimal Decimal::subtract(const Decimal& other) const {
    return subtractDigits(other);
}

// Copy operation
Decimal Decimal::copy() const {
    return Decimal(*this);
}

// Comparison operations
bool Decimal::isGreater(const Decimal& other) const {
    return isGreaterThan(other);
}

bool Decimal::isLess(const Decimal& other) const {
    return isLessThan(other);
}

bool Decimal::isEqual(const Decimal& other) const {
    return isEqualTo(other);
}

// Assignment arithmetic operations
Decimal& Decimal::addAssign(const Decimal& other) {
    *this = add(other);
    return *this;
}

Decimal& Decimal::subtractAssign(const Decimal& other) {
    *this = subtract(other);
    return *this;
}

// Utility methods
std::string Decimal::toString() const {
    if (digits.empty()) {
        return "0";
    }
    
    std::string result;
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        result += static_cast<char>(digits[i] + '0');
    }
    
    return result;
}

size_t Decimal::getDigitCount() const {
    return digits.size();
}

unsigned char Decimal::getDigit(size_t index) const {
    if (index >= digits.size()) {
        throw std::out_of_range("Digit index out of range");
    }
    return digits[index];
}

bool Decimal::isEmpty() const {
    return digits.empty() || (digits.size() == 1 && digits[0] == 0);
}

// Static factory methods
Decimal Decimal::fromString(const std::string& number) {
    return Decimal(number);
}

Decimal Decimal::zero() {
    return Decimal();
}
