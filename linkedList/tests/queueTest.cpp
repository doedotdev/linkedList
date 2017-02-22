//
// Created by Benjamin D. Horn on 2/22/17.
//\
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "queue.h"

using testing::Eq;

namespace {
    class testQueue : public testing::Test {
    public:
    };
}

TEST_F(testQueue, test1){
    ASSERT_EQ(0,0);
}

TEST_F(testQueue, test2){
    queue<int> a;
    queue<int> b(a);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(testQueue, test3){
    queue<int> a;
    a.enqueue(3);
    queue<int> b(a);
    ASSERT_EQ(b.front(), 3);
}

TEST_F(testQueue, test4){
    queue<int> a;
    a.enqueue(3);
    a.dequeue();
    queue<int> b(a);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(testQueue, test5){
    queue<int> a;
    a.enqueue(8);
    queue<int> b = a;
    ASSERT_EQ(b.front(), a.front());
}

TEST_F(testQueue, test6){
    queue<int> a;
    a.enqueue(7);
    a.enqueue(10);
    queue<int> b = a;
    ASSERT_EQ(b.size(), a.size());
}

TEST_F(testQueue, test7){
    queue<int> a;
    queue<int> b = a;
    ASSERT_EQ(b.size(), 0);
}

TEST_F(testQueue, test8){
    queue<int> a;
    a.enqueue(4);
    a.enqueue(0);
    ASSERT_EQ(a.front(), 4);
}

TEST_F(testQueue, test9){
    queue<int> a;
    a.enqueue(-4);
    ASSERT_EQ(a.front(), -4);
}

TEST_F(testQueue, test10){
    queue<int> a;
    a.enqueue(10);
    a.dequeue();
    a.enqueue(5);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(testQueue, test11){
    queue<int> a;
    a.enqueue(0);
    ASSERT_EQ(a.front(), 0);
}

TEST_F(testQueue, test12){
    queue<int> a;
    a.enqueue(-6);
    a.dequeue();
    ASSERT_ANY_THROW(a.front());
}

TEST_F(testQueue, test13){
    queue<int> a;
    a.enqueue(111111);
    a.enqueue(2);
    a.dequeue();
    ASSERT_EQ(a.front(), 2);
}

TEST_F(testQueue, test14){
    queue<int> a;
    a.enqueue(-7);
    a.dequeue();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testQueue, test15){
    queue<int> a;
    a.dequeue();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testQueue, test16){
    queue<int> a;
    a.enqueue(-4);
    a.enqueue(23);
    a.dequeue();
    ASSERT_EQ(a.front(), 23);
}

TEST_F(testQueue, test17){
    queue<int> a;
    a.enqueue(1);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(testQueue, test18){
    queue<int> a;
    a.enqueue(-4);
    a.enqueue(6);
    ASSERT_EQ(a.size(), 2);
}

TEST_F(testQueue, test19){
    queue<int> a;
    a.enqueue(-4);
    a.dequeue();
    a.enqueue(2);
    a.dequeue();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testQueue, test20){
    queue<int> a;
    a.enqueue(48);
    a.dequeue();
    ASSERT_TRUE(a.isEmpty() == true);
}

TEST_F(testQueue, test21){
    queue<int> a;
    ASSERT_TRUE(a.isEmpty() == true);
}

TEST_F(testQueue, test22){
    queue<int> a;
    a.enqueue(30);
    ASSERT_TRUE(a.isEmpty() == false);
}