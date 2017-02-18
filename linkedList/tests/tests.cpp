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

    ASSERT_EQ(int_objects.size(),list_size);
}