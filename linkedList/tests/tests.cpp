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

/**
    *Remove
*/

TEST_F(testClass, remove1) {
    doublyLinkedList<int> a;
    ASSERT_EQ(a.size(), 0);
    ASSERT_ANY_THROW(a.remove(0));
}

TEST_F(testClass, remove2) {
    doublyLinkedList<int> a;
    a.push_front(5);
    ASSERT_EQ(a.size(), 1);
    a.remove(0);
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testClass, remove3) {
    doublyLinkedList<int> a;
    a.push_front(5);
    ASSERT_EQ(a.size(), 1);
    a.remove(-1);
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testClass, remove4) {
    doublyLinkedList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    ASSERT_EQ(a.size(), 3);
    a.remove(-1);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.getAt(0), 5);
    ASSERT_EQ(a.getAt(1), 6);
    ASSERT_ANY_THROW(a.getAt(2));
}

TEST_F(testClass, remove5) {
    doublyLinkedList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    ASSERT_EQ(a.size(), 3);
    a.remove(1);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.getAt(0), 5);
    ASSERT_EQ(a.getAt(1), 7);
}

TEST_F(testClass, remove6) {
    doublyLinkedList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    ASSERT_EQ(a.size(), 3);
    a.remove(-2);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.getAt(0), 5);
    ASSERT_EQ(a.getAt(1), 7);
}

TEST_F(testClass, remove7) {
    doublyLinkedList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    ASSERT_EQ(a.size(), 3);
    a.remove(-1);
    ASSERT_EQ(a.size(), 2);
    a.remove(-1);
    ASSERT_EQ(a.size(), 1);
    a.remove(-1);
    ASSERT_EQ(a.size(), 0);
    ASSERT_ANY_THROW(a.remove(-1));
}

TEST_F(testClass, remove8) {
    doublyLinkedList<int> a;
    for(int i = 0 ; i < SIZE; i++){
        a.push_front(i*2);
    }
    // How fast is deleting the first element?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
        a.remove(0);
    }
    clock_t first_stop = clock();
    // How fast removing the last element?
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
        a.remove(-1);
    }
    clock_t last2_stop = clock();
    EXPECT_NEAR(first_stop - first_start, last2_stop - last2_start, 500);
}

TEST_F(testClass, remove9) {
    doublyLinkedList<int> a;
    const int SIZE = 1000;
    for(int i = 0 ; i < SIZE; i++){
        a.push_front(i*2);
    }
    // How fast is deleting the first element?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
        a.remove(0);
    }
    clock_t first_stop = clock();
    // How fast removing the last element?
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
        a.remove(-2);
    }
    clock_t last2_stop = clock();
    EXPECT_NEAR(first_stop - first_start, last2_stop - last2_start, 500);
}

/**
    *Reverse
*/

TEST_F(testClass, reverse) {
    doublyLinkedList<int> a;
    doublyLinkedList<int> b = a.reverse();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(testClass, reverse1) {
    doublyLinkedList<int> a;
    a.push_back(5);
    doublyLinkedList<int> b = a.reverse();
    
    ASSERT_EQ(a.size(), 1);
    
    ASSERT_EQ(b.size(), 1);
    
    ASSERT_EQ(a.getAt(0), 5);
    
    ASSERT_EQ(b.getAt(0), 5);
}

TEST_F(testClass, reverse2) {
    doublyLinkedList<int> a;
    a.push_back(5);
    a.push_back(6);
    doublyLinkedList<int> b = a.reverse();
    
    ASSERT_EQ(a.size(), 2);
    
    ASSERT_EQ(b.size(), 2);
    
    ASSERT_EQ(a.getAt(0), 5);
    
    ASSERT_EQ(b.getAt(0), 6);
    
    ASSERT_EQ(a.getAt(1), 6);
    
    ASSERT_EQ(b.getAt(1), 5);
}

TEST_F(testClass, reverse3) {
    doublyLinkedList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    doublyLinkedList<int> b = a.reverse();
    
    ASSERT_EQ(a.size(), 3);
    
    ASSERT_EQ(b.size(), 3);
    
    ASSERT_EQ(a.getAt(0), 5);
    
    ASSERT_EQ(b.getAt(0), 7);
    
    ASSERT_EQ(a.getAt(1), 6);
    
    ASSERT_EQ(b.getAt(1), 6);
    
    ASSERT_EQ(a.getAt(2), 7);
    
    ASSERT_EQ(b.getAt(2), 5);
}

TEST_F(testClass, reverse4) {
    doublyLinkedList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    doublyLinkedList<int> b = a.reverse();
    
    ASSERT_EQ(a.size(), 4);
    
    ASSERT_EQ(b.size(), 4);
    
    ASSERT_EQ(a.getAt(0), 5);
    
    ASSERT_EQ(b.getAt(0), 8);
    
    ASSERT_EQ(a.getAt(1), 6);
    
    ASSERT_EQ(b.getAt(1), 7);
    
    ASSERT_EQ(a.getAt(2), 7);
    
    ASSERT_EQ(b.getAt(2), 6);
    
    ASSERT_EQ(a.getAt(3), 8);
    
    ASSERT_EQ(b.getAt(3), 5);
}

/**
    *add
*/


TEST_F(testClass, add) {
    doublyLinkedList<int> c = doublyLinkedList<int>() + doublyLinkedList<int>();
    ASSERT_EQ(c.size(), 0);
}

TEST_F(testClass, add1) {
    doublyLinkedList<int> a;
    a.push_back(5);
    doublyLinkedList<int> b;
    b.push_back(10);
    doublyLinkedList<int> c = a + b;
    
    ASSERT_EQ(a.size(), 1);
    
    ASSERT_EQ(b.size(), 1);
    
    ASSERT_EQ(c.size(), 2);
    
    ASSERT_EQ(c.getAt(0), 5);
    
    ASSERT_EQ(c.getAt(1), 10);
}

TEST_F(testClass, add2) {
    doublyLinkedList<int> a;
    doublyLinkedList<int> b;
    b.push_back(10);
    b.push_back(11);
    doublyLinkedList<int> c = a + b;
    
    ASSERT_EQ(a.size(), 0);
    
    ASSERT_EQ(b.size(), 2);
    
    ASSERT_EQ(c.size(), 2);
    
    ASSERT_EQ(c.getAt(0), 10);
    
    ASSERT_EQ(c.getAt(1), 11);
}

/**
    *eq
*/


TEST_F(testClass, eq) {
    doublyLinkedList<int> a;
    doublyLinkedList<int> b;
    ASSERT_TRUE( a == b);
    ASSERT_TRUE( !(a != b));
}

TEST_F(testClass, eq1) {
    doublyLinkedList<int> a;
    a.push_back(6);
    doublyLinkedList<int> b;
    b.push_front(6);
    ASSERT_TRUE( a == b);
    ASSERT_TRUE( !(a != b));
}

TEST_F(testClass, eq2) {
    doublyLinkedList<int> a;
    a.push_back(6);
    doublyLinkedList<int> b;
    ASSERT_TRUE( a != b);
    ASSERT_TRUE( !(a == b));
}

TEST_F(testClass, eq3) {
    doublyLinkedList<int> a;
    doublyLinkedList<int> b;
    b.push_front(6);
    ASSERT_TRUE( a != b);
    ASSERT_TRUE( !(a == b));
}

TEST_F(testClass, eq4) {
    doublyLinkedList<int> a;
    a.push_back(6);
    doublyLinkedList<int> b;
    a.push_front(7);
    ASSERT_TRUE( a != b);
    ASSERT_TRUE( !(a == b));
}

TEST_F(testClass, eq5) {
    doublyLinkedList<int> a;
    a.push_front(5);
    a.push_back(6);
    doublyLinkedList<int> b;
    b.push_front(6);
    b.push_front(5);
    ASSERT_TRUE( a == b);
    ASSERT_TRUE( !(a != b));
}

/**
    *clear
*/


TEST_F(testClass, clear){
    doublyLinkedList<int> a;
    a.clear();
    
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testClass, clear1){
    doublyLinkedList<int> a;
    a.push_back(6);
    
    ASSERT_EQ(a.size(), 1);
    a.clear();
    
    ASSERT_EQ(a.size(), 0);
}

TEST_F(testClass, clear2){
    doublyLinkedList<int> a;
    a.push_back(6);
    
    ASSERT_EQ(a.size(), 1);
    a.clear();
    
    ASSERT_EQ(a.size(), 0);
    a.push_back(7);
    
    ASSERT_EQ(a.getAt(0), 7);
}

/**
    *testStream
*/

TEST_F(testClass, stream){
    doublyLinkedList<int> a;
    a.push_back(5);
    a.push_back(6);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    
    ASSERT_EQ(out, "[5,6]");
}

TEST_F(testClass, stream1){
    doublyLinkedList<int> a;
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    
    ASSERT_EQ(out, "[]");
}

TEST_F(testClass, stream2){
    doublyLinkedList<float> a;
    a.push_back(5.5);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    
    ASSERT_EQ(out, "[5.5]");
}

TEST_F(testClass, stream3){
    doublyLinkedList<string> a;
    a.push_back("stuff");
    a.push_back("more");
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    
    ASSERT_EQ(out, "[stuff,more]");
}

TEST_F(testClass, stream4){
    doublyLinkedList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    
    ASSERT_EQ(out, "[5,6,7]");
}

TEST_F(testClass, testEdge){
    doublyLinkedList<int> a;
    const int size = 200;
    for(int i = 0; i < size; i++){
        a.push_back(i);
        a.push_back(i);
        a.push_front(i);
        a.remove(-1);
        
    ASSERT_EQ(a.size(), (i+1) * 2);
    }
    // Make sure the sum is OK  Yes, this is very slow!
    long long int count = 0;
    for(unsigned int i = 0; i < a.size(); i++){
        count = count +  a.getAt(i);
    }
    
    ASSERT_EQ(count, size * (size - 1)); // Does the count match?
    
    ASSERT_EQ(a.size(), size * 2);

    for(int i = 0; i < size; i++){
        a.remove(-1);
        a.remove(0);
    }
    
    ASSERT_EQ(a.size(), 0);
}
