#include <gtest/gtest.h>
#include "DoublyLinkedListTest.h"
#include "StackTest.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}