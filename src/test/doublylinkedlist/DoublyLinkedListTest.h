/**
 * @file    DoublyLinkedListTest.cpp
 * @author  (original JAVA) William Fiset, william.alexandre.fiset@gmail.com
 *          (conversion to C++) Toan Dang, dangnhattoan@gmail.com 
 * @date    Nov 08, 2022
 * @version 0.1
 * @brief   A doubly linked list test
*/

#ifndef D_LINKED_LIST_TEST_H
#define D_LINKED_LIST_TEST_H

#include <iostream>
#include <list>
#include <DoublyLinkedList.h>

#include <type_traits>
#include <vector>
#include <gtest/gtest.h>

namespace dsa {
    class LinkListTest : public testing::Test {
        protected:
            doubly_linked_list<int> *list;

            LinkListTest() {
                list = nullptr;
                list = new doubly_linked_list<int>();
            }

            ~LinkListTest() {
                if (list) delete list;
            }

            virtual void SetUp() {}
            virtual void TearDown() {
                list->erase(list->begin(), list->end());
            }
    };

#if 1
    TEST_F(LinkListTest, testEmptyList) {
        EXPECT_TRUE(list->empty());
        EXPECT_EQ(list->size(), 0);
    }

    TEST_F(LinkListTest, testPopFrontOfEmpty) {
        try {
            list->pop_front();
        } 
        catch(const std::runtime_error& err) {
            EXPECT_EQ(err.what(), std::string("Empty list"));
        }
        catch(...) {
            FAIL() << "Expected std::runtime_error Empty list";
        }

    }

    TEST_F(LinkListTest, testPushBack) {
        list->push_back(3);
        ASSERT_EQ(list->size(), 1);
        list->push_back(5);
        ASSERT_EQ(list->size(), 2);
    }

    TEST_F(LinkListTest, testPushFront) {
        list->push_front(3);
        ASSERT_EQ(list->size(), 1);
        list->push_front(5);
        ASSERT_EQ(list->size(), 2);
    }

    TEST_F(LinkListTest, testEmplaceBack) {
        list->emplace_back(1);
        ASSERT_EQ(list->size(), 1);
        list->emplace_back(2);
        ASSERT_EQ(list->size(), 2);
    }
    /* Iterator */
    TEST_F(LinkListTest, testBegin) {
        list->push_front(1);
        list->push_front(2);
        list->push_front(3);
        EXPECT_EQ(*(list->begin()), 3);
        list->pop_front();
        EXPECT_EQ(*(list->begin()), 2);
        list->pop_front();
        EXPECT_EQ(*(list->begin()), 1);
    }

    TEST_F(LinkListTest, testCBegin) {
        list->push_front(1);
        list->push_front(2);
        list->push_front(3);
        EXPECT_EQ(*(list->cbegin()), 3);
        list->pop_front();
        EXPECT_EQ(*(list->cbegin()), 2);
        list->pop_front();
        EXPECT_EQ(*(list->cbegin()), 1);
    }

    TEST_F(LinkListTest, testEnd) {
        EXPECT_EQ(list->end(), dsa::doubly_linked_list<int>::iterator(nullptr));
    }

    TEST_F(LinkListTest, testCEnd) {
        EXPECT_EQ(list->cend(), dsa::doubly_linked_list<int>::iterator(nullptr));
    }

    /* Element access */
    TEST_F(LinkListTest, testFront) {
        list->push_front(1);
        list->push_front(2);
        list->push_front(3);
        EXPECT_EQ(list->front(), 3);
        list->pop_front();
        EXPECT_EQ(list->front(), 2);
        list->pop_front();
        EXPECT_EQ(list->front(), 1);
    }

    TEST_F(LinkListTest, testBack) {
        list->push_front(1);
        list->push_front(2);
        list->push_front(3);
        EXPECT_EQ(list->back(), 1);
        list->pop_back();
        EXPECT_EQ(list->back(), 2);
        list->pop_back();
        EXPECT_EQ(list->back(), 3);
    }

    /* pop_back */
    TEST_F(LinkListTest, testPopBackOfEmpty) {
        try {
            list->pop_back();
        } catch(const std::runtime_error& err) {
            EXPECT_EQ(err.what(), std::string("Empty list"));
        } catch(...) {
            FAIL() << "Expected std::runtime_err Empty list";
        }
    }
    
    TEST_F(LinkListTest, testPopBackNonEmpty) {
        list->push_back(1);
        list->push_back(2);
        list->push_back(3);
        EXPECT_EQ(list->size(), 3);
        list->pop_back();
        EXPECT_EQ(list->size(), 2);
        list->pop_back();
        EXPECT_EQ(list->size(), 1);
    }

    /* erase */
    TEST_F(LinkListTest, testEraseNon) {
        try {
            list->erase(dsa::doubly_linked_list<int>::iterator(nullptr));
        }catch (const std::runtime_error& err) {
            EXPECT_EQ(err.what(), std::string("Non-dereferenceable iterator"));
        }catch(...) {
            FAIL() << "Expected std::runtime_error Non-dereferenceable iterator";
        }
    }

    TEST_F(LinkListTest, testErasePos) {
        list->push_back(1);
        list->push_back(2);
        list->push_back(3);
        EXPECT_EQ(list->size(), 3);
        list->erase(list->begin());
        EXPECT_EQ(list->size(), 2);
        list->erase(list->begin());
        EXPECT_EQ(list->size(), 1);
        list->erase(list->begin());
        EXPECT_EQ(list->size(), 0);
    }

    TEST_F(LinkListTest, testEraseFirstLast) {
        list->push_back(1);
        list->push_back(2);
        list->push_back(3);
        list->erase(list->begin(), list->end());
        EXPECT_EQ(list->size(), 0);
    }


#endif  /* if 0 */
}   /* namespace dsa */

#endif /* D_LINKED_LIST_H */