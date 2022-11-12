/**
 * @file    StackTest.cpp
 * @author  (original JAVA) William Fiset, william.alexandre.fiset@gmail.com
 *          (conversion to C++) Toan Dang, dangnhattoan@gmail.com 
 * @date    Nov 09, 2022
 * @version 0.1
 * @brief   A doubly linked list test
*/

#ifndef STACK_TEST_H
#define STACK_TEST_H

#include <iostream>
#include <list>
#include <array>
#include "Stack.h"

#include <type_traits>
#include <vector>
#include <gtest/gtest.h>


namespace dsa {
    class StackTest : public testing::Test {
        protected:
            stack<int, dsa::doubly_linked_list<int>> my_stack;

        public:
            StackTest() {}
            virtual ~StackTest() {}
            virtual void SetUp() {}
            virtual void TearDown() {}
    };

#if 1
    TEST_F(StackTest, testEmptyStack) {
        EXPECT_TRUE(my_stack.empty());
        EXPECT_EQ(my_stack.size(), 0);
    }

    TEST_F(StackTest, testPush) {
        my_stack.push(1);
        my_stack.push(2);
        my_stack.push(3);
        EXPECT_FALSE(my_stack.empty());
        EXPECT_EQ(my_stack.size(), 3);
        EXPECT_EQ(my_stack.top(), 3);
        my_stack.pop();
        EXPECT_EQ(my_stack.size(), 2);
        EXPECT_EQ(my_stack.top(), 2);
        my_stack.pop();
        EXPECT_EQ(my_stack.size(), 1);
        EXPECT_EQ(my_stack.top(), 1);
    }
#endif /* if 0 */
}   /* namespace dsa */

#endif /* STACK_TEST_H */
