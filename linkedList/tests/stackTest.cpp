//
// Created by Benjamin D. Horn on 2/22/17.
//\
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "stack.h"

using testing::Eq;

namespace {
    class testStack : public testing::Test {
    public:
    };
}

/**
 * test size function
*/

TEST_F(testStack, test1){
    ASSERT_EQ(0,0);
}

TEST_F(testStack, test2){
    stack<int> a;
    stack<int> b(a);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(testStack, test3){
    stack<int> a;
    a.push(3);
    stack<int> b(a);
    ASSERT_EQ(b.top(), 3);
}

TEST_F(testStack, test4){
    stack<int> a;
    a.push(3);
    a.pop();
    stack<int> b(a);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(testStack, test5){
    stack<int> a;
    a.push(8);
    stack<int> b = a;
    ASSERT_EQ(b.top(), a.top());
}

TEST_F(testStack, test6){
    stack<int> a;
    a.push(7);
    a.push(10);
    stack<int> b = a;
    ASSERT_EQ(b.size(), a.size());
}

TEST_F(testStack, test7){
    stack<int> a;
    stack<int> b = a;
    ASSERT_EQ(b.size(), 0);
}

TEST_F(testStack, test8){
    stack<int> a;
    a.push(4);
    a.push(0);
    ASSERT_EQ(a.top(), 0);
}

TEST_F(testStack, test9){
    stack<int> a;
    a.push(-4);
    ASSERT_EQ(a.top(), -4);
}

TEST_F(testStack, test10){
    stack<int> a;
    a.push(10);
    a.pop();
    a.push(5);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(testStack, test11){
    stack<int> a;
    a.push(0);
    ASSERT_EQ(a.top(), 0);
}

TEST_F(testStack, test12){
    stack<int> a;
    a.push(-6);
    a.pop();
    ASSERT_ANY_THROW(a.top());
}

TEST_F(testStack, test13){
    stack<int> a;
    a.push(111111);
    a.push(2);
    ASSERT_EQ(a.top(), 2);
}

TEST_F(testStack, test14){
    stack<int> a;
    a.push(-7);
    a.pop();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testStack, test15){
    stack<int> a;
    a.pop();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testStack, test16){
    stack<int> a;
    a.push(-4);
    a.push(23);
    a.pop();
    ASSERT_EQ(a.top(), -4);
}

TEST_F(testStack, test17){
    stack<int> a;
    a.push(1);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(testStack, test18){
    stack<int> a;
    a.push(-4);
    a.push(6);
    ASSERT_EQ(a.size(), 2);
}

TEST_F(testStack, test19){
    stack<int> a;
    a.push(-4);
    a.pop();
    a.push(2);
    a.pop();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testStack, test20){
    stack<int> a;
    a.push(48);
    a.pop();
    ASSERT_TRUE(a.isEmpty() == true);
}

TEST_F(testStack, test21){
    stack<int> a;
    ASSERT_TRUE(a.isEmpty() == true);
}

TEST_F(testStack, test22){
    stack<int> a;
    a.push(30);
    ASSERT_TRUE(a.isEmpty() == false);
}