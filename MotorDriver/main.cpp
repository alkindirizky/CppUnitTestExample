#define CATCH_CONFIG_MAIN

#include <catch.hpp>

// Intended empty source for Catch Unit Testing main()

// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -c 020-TestCase-1.cpp
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 020-TestCase TestCase-1.o 020-TestCase-2.cpp && 020-TestCase --success
//
// For CLANG:
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% -c 020-TestCase-1.cpp
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% -Fe020-TestCase.exe 020-TestCase-1.obj 020-TestCase-2.cpp && 020-TestCase --success