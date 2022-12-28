#include <gtest/gtest.h>
#include "DoublyLinkedListTest.h"
#include "StackTest.h"
#include "QueueTest.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}