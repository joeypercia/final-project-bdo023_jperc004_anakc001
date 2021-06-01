#include "task.hpp"
#include "print.hpp"

#include "gtest/gtest.h"

#include "test.cpp"

// ADD UNIT TESTS HERE
int main(int argc, char **argv) { // Using Google Test Git Submodule to run the Unit Tests
     ::testing::InitGoogleTest(&argc, argv);
         return RUN_ALL_TESTS();
return 0;
}
