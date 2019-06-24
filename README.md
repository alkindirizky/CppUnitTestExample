CppUnitTestExample

This repo consists of 3 examples of unit-testing using Catch2 and mocking via Fakeit, they are placed in folder:
- CircularBuffer
- MotorDriver
- SerialProcessor

The problem without solution is in branch "master", while example with filled solution is in branch "solved"

Each folder consists of 3 main files:
- Modules (with name of xx.cpp, with xx being module/folder name) : module that is being tested
- Test Cases (with name of xxTest.cpp, with xx being module/folder name) : test cases used for unit-testing the modules
- Main file (main.cpp) : which is basically empty source file with Catch2 inclusion. This is needed to run the example

You can compile it via makefile and gcc (or your own compiler choice) OR you can open each example using CodeBlocks
