//
// Created by Benjamin D. Horn on 2/18/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "doublyLinkedList.h"

using testing::Eq;

namespace {
    class testClass : public testing::Test {
    public:
        doublyLinkedList<int> int_objects;
        doublyLinkedList<string> string_objects;
        const int SIZE = 2000;
    };
}

/**
 * test size function
*/

TEST_F(testClass, testSize1){
    ASSERT_EQ(int_objects.size(),0);
}

TEST_F(testClass, testSize2){
    ASSERT_EQ(string_objects.size(),0);
}

TEST_F(testClass, testSize3){
    int_objects.push_back(1);
    ASSERT_EQ(int_objects.size(),1);
}

TEST_F(testClass, testSize4){
    int list_size = 300;
    for(int i = 0; i < list_size; i++){
        int_objects.push_back(i);
    }

    ASSERT_EQ(int_objects.size(),list_size);
}

/**
 * copy constructor
*/

TEST_F(testClass, testCopy1){

    doublyLinkedList<int> b(int_objects);
    ASSERT_EQ(b.size(),  int_objects.size());
}

TEST_F(testClass, testCopy2){

    doublyLinkedList<int> b(int_objects);
    ASSERT_EQ(b.size(),  int_objects.size());
}

TEST_F(testClass, testCopy3){

    doublyLinkedList<int> b(int_objects);
    ASSERT_EQ(b.size(),  int_objects.size());
}

TEST_F(testClass, testCopy4){
    doublyLinkedList<int> c;
    c.push_back(1);
    c.push_front(2);
    c.push_back(3);

    doublyLinkedList<int> d(c); // make d and copy c to it
    ASSERT_EQ(c.size(),  d.size());
}

TEST_F(testClass, testCopy5){
    doublyLinkedList<int> c;
    c.push_back(1);
    c.push_front(2);
    c.push_back(3);

    doublyLinkedList<int> d(c); // make d and copy c to it
    ASSERT_EQ(c.getAt(0), d.getAt(0));
}

TEST_F(testClass, testCopy6){
    doublyLinkedList<string> c;
    c.push_back("hello");
    c.push_front("how");
    c.push_back("are");
    c.push_front("you");
    c.push_back("?");
    doublyLinkedList<string> d(c); // make d and copy c to it
    ASSERT_EQ(c.getAt(0), d.getAt(0));
}

TEST_F(testClass, testCopy7){
    doublyLinkedList<int> c;
    c.push_back(1);
    c.push_front(2);
    c.push_back(3);

    doublyLinkedList<int> d;
    d.push_back(5);
    c = d;
    ASSERT_EQ(c.getAt(0), d.getAt(0));
}

TEST_F(testClass, testCopy8){
    doublyLinkedList<string> c;
    c.push_back("hello");
    c.push_front("how");
    c.push_back("are");
    c.push_front("you");
    c.push_back("?");
    doublyLinkedList<string> d; // make d and copy c to it
    d.push_back("hello");
    c = d;
    ASSERT_EQ(c.getAt(0), d.getAt(0));
}

/**
 * pushing on the front and back of the list
*/

TEST_F(testClass, testPush1){
    doublyLinkedList<int> a;
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testClass, testPush2){
    doublyLinkedList<int> a;
    a.push_back(1);
    a.push_front(2);
    a.push_back(3);
    ASSERT_EQ(a.getAt(0), 2);
}

TEST_F(testClass, testPush3){
    doublyLinkedList<int> a;
    a.push_back(1);
    a.push_front(2);
    a.push_back(3);
    ASSERT_EQ(a.size(), 3);
}

TEST_F(testClass, testPush4){
    doublyLinkedList<int> a;
    a.push_back(1);
    a.push_front(2);
    a.push_back(3);
    ASSERT_EQ(a.getAt(2), 3);
}

TEST_F(testClass, testPush5){
        doublyLinkedList<int> a;
        a.push_back(1);
        a.push_front(2);
        a.push_back(3);
        ASSERT_ANY_THROW(a.getAt(4));
}


/**
 * getAt
*/

TEST_F(testClass, testGet1){
    doublyLinkedList<int> a;
    ASSERT_ANY_THROW(a.getAt(0));
}

TEST_F(testClass, testGet2){
    doublyLinkedList<int> a;
    a.push_back(2);
    ASSERT_ANY_THROW(a.getAt(3));
}

TEST_F(testClass, testGet3){
    doublyLinkedList<string> a;
    ASSERT_ANY_THROW(a.getAt(0));
}

/**
    *Speed
*/


TEST_F(testClass, speedGetAt) {
    doublyLinkedList<int> a;
    for(int i = 0 ; i < SIZE; i++){
        a.push_front(i*2);
    }
    // How fast is accessing the first element?
    int sum = 0;
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE; i++){
        sum += a.getAt(0);
    }
    clock_t first_stop = clock();
    // How fast for the second to last?
    int sum2 = 0;
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE; i++){
        sum2 += a.getAt(-2);
    }
    clock_t last2_stop = clock();
    EXPECT_NEAR(first_stop - first_start, last2_stop - last2_start, 100);
}

TEST_F(testClass, speedSetAt) {
    doublyLinkedList<int> a;
    for(int i = 0 ; i < SIZE; i++){
        a.push_front(i*2);
    }
    // How fast is accessing the beginning elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
        a.setAt(42,i);
    }
    clock_t first_stop = clock();
    // How fast for accessing the last elements?
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
        a.setAt(42,SIZE - i - 1);
    }
    clock_t last2_stop = clock();
    EXPECT_NEAR(first_stop - first_start, last2_stop - last2_start, 500);
}