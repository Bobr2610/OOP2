# OOP Lab 2 - Decimal Class Implementation

This project implements a `Decimal` class for working with unsigned integer decimal numbers using dynamic arrays as specified in the requirements.

## Project Structure

```
OOP_LAB_2/
├── CMakeLists.txt          # Main CMake configuration
├── code/                   # Source code directory
│   ├── CMakeLists.txt      # Code CMake configuration
│   ├── decimal.h           # Decimal class header
│   ├── decimal.cpp         # Decimal class implementation
│   └── main.cpp            # Main demonstration program
├── tests/                  # Unit tests directory
│   ├── CMakeLists.txt      # Tests CMake configuration
│   └── unit_tests.cpp      # Unit tests implementation
└── README.md               # This file
```

## Class Implemented

### Decimal Class

The `Decimal` class works with unsigned integer decimal numbers using an array of `unsigned char` elements where each element represents a decimal digit (0-9). The least significant digit (units) is stored at index 0.

**Features:**
- Immutable design (objects don't change after creation)
- Large number support (limited only by available memory)
- Proper decimal arithmetic with carry/borrow handling
- Exception handling for invalid inputs and operations
- All operations return new object instances

**Key Methods:**
- Constructors: `Decimal()`, `Decimal(string)`, `Decimal(unsigned long long)`, `Decimal(const Decimal&)`, `Decimal(Decimal&&)`
- Arithmetic: `add()`, `subtract()`, `copy()`
- Comparison: `isGreater()`, `isLess()`, `isEqual()`
- Assignment: `addAssign()`, `subtractAssign()`
- Utilities: `toString()`, `getDigitCount()`, `getDigit()`, `isEmpty()`
- Static factories: `fromString()`, `fromNumber()`, `zero()`

## Requirements Compliance

✅ **Class Structure**: Class is divided into interface (.h) and implementation (.cpp)

✅ **Self-definition**: Independently defined types, fields, and methods

✅ **Exception Handling**: Standard exceptions used in constructors and methods

✅ **Arithmetic Operations**: Addition, subtraction, and copying implemented

✅ **Comparison Operations**: Greater than, less than, and equal to implemented

✅ **Assignment Arithmetic**: Implemented as class methods (addAssign, subtractAssign)

✅ **Immutability**: Class objects are immutable; methods return new object instances

✅ **No Operator Overloading**: As requested, operator overloading is not used for arithmetic operations

## Building and Running

### Prerequisites
- CMake 3.16 or higher
- C++17 compatible compiler
- Google Test (automatically downloaded via CMake)

### Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .

# Run the main program
./code/OOP_LAB_2

# Run unit tests
./tests/unit_tests
```

### Alternative Build (using make)

```bash
mkdir build
cd build
cmake ..
make
```

## Testing

The project includes comprehensive unit tests covering:

- All constructors and destructors
- Copy and move semantics
- Arithmetic operations
- Comparison operations
- Exception handling
- Edge cases and large numbers
- Immutability verification

Run tests with:
```bash
cd build
./tests/unit_tests
```

## Example Usage

### Decimal Class
```cpp
// Create decimal numbers
Decimal dec1("12345");
Decimal dec2(67890);

// Arithmetic operations (immutable)
Decimal sum = dec1.add(dec2);
Decimal diff = dec2.subtract(dec1);

// Comparison operations
bool isGreater = dec2.isGreater(dec1);
bool isEqual = dec1.isEqual(dec1);

// Assignment operations
dec1.addAssign(dec2);  // dec1 is now 12345 + 67890
```

## Design Decisions

1. **Immutability**: Both classes follow immutable design patterns where operations return new objects
2. **Exception Safety**: Proper exception handling with standard exceptions
3. **Memory Management**: RAII principles with proper resource cleanup
4. **Decimal Representation**: Least significant digit at index 0 for natural arithmetic
5. **Large Number Support**: Dynamic allocation allows for arbitrarily large numbers
6. **Type Safety**: Strong typing with appropriate access controls

## Error Handling

- **Invalid Input**: `std::invalid_argument` for malformed decimal strings
- **Out of Range**: `std::out_of_range` for array index access
- **Arithmetic Errors**: `std::invalid_argument` for invalid operations (e.g., subtracting larger from smaller)

## Performance Considerations

- Move semantics implemented for efficient object transfers
- Minimal memory allocations through proper copy/move constructors
- Efficient string operations for large numbers
- RAII for automatic resource management
