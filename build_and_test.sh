#!/bin/bash

echo "Building OOP Lab 2 Project..."
echo

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Configure with CMake
echo "Configuring with CMake..."
cmake ..
if [ $? -ne 0 ]; then
    echo "CMake configuration failed!"
    exit 1
fi

# Build the project
echo "Building project..."
cmake --build .
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

echo
echo "Build successful!"
echo

# Run the main program
echo "Running main program..."
echo "================================"
./code/OOP_LAB_2
echo "================================"
echo

# Run unit tests
echo "Running unit tests..."
echo "================================"
./tests/unit_tests
echo "================================"
echo

echo "All done!"

