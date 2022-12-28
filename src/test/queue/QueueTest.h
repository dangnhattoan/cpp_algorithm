/**
 * @file    QueueTest.h
 * @author  (original JAVA) William Fiset, william.alexandre.fiset@gmail.com
 *          (conversion to C++) Toan Dang, dangnhattoan@gmail.com 
 * @date    Dec 26, 2022
 * @version 0.1
 * @brief   A queue test
*/


#include <iostream>

#include <list>
#include <array>

#include <gtest/gtest.h>

#include "queue.h"

#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H

namespace dsa {

    class QueueTest : public testing::Test {
        protected:
            queue<int> my_queue;

        public:
            QueueTest() {}
            virtual ~QueueTest() {}
            virtual void SetUp() {}
            virtual void TearDown() {}
    };


    TEST_F(QueueTest, testEmptyQueue) {
        EXPECT_TRUE(my_queue.empty());
        EXPECT_EQ(my_queue.size(), 0);
    }

    TEST_F(QueueTest, testSizeQueue) {
        my_queue.push(1);
        EXPECT_EQ(my_queue.size(), 1);
        my_queue.push(2);
        EXPECT_EQ(my_queue.size(), 2);
    }

    TEST_F(QueueTest, testFrontPushPop) {
        my_queue.push(1);
        EXPECT_EQ(my_queue.front(), 1);
        my_queue.push(2);
        my_queue.pop();
        EXPECT_EQ(my_queue.front(), 2);
    }

    TEST_F(QueueTest, testBackPushPop) {
        my_queue.push(1);
        my_queue.push(2);
        EXPECT_EQ(my_queue.back(), 2);
        my_queue.pop();
        EXPECT_EQ(my_queue.back(), 2);
    }

}   /* namespace dsa */

#endif /* QUEUE_TEST_H */