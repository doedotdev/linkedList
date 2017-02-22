//
// Created by Benjamin D. Horn on 2/22/17.
//

#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

/*
	Stack implementation using a LList.
	Jeremiah Greer
	September 2015
*/
#include <ostream>
#include <stdexcept>

#include "doublyLinkedList.h"

using namespace std;


template <class T>
class stack{

// Fill me in!
public:
    // Constructor
    stack(){
        doublyLinkedList<T> cont;
    }

    // Destructor
    ~stack(){
        cont.clear();
    }

    // Copy Constructor
    stack(const stack& other){
        this->cont = other.cont;
    }

    // Assignment Overload
    stack<T>& operator= (const stack& other){
        cont = other.cont;
    }

    // Puts new item on top of stack
    void push(T value){
        cont.push_front(value);
    }

    // Returns top element
    T top(){
        if(cont.size() == 0){
            throw logic_error("Empty Stack!");
        }
        return cont.getAt(0);
    }

    // Removes top element
    void pop(){
        if(cont.size() != 0){
            cont.remove(0);
        }
    }

    // Returns size
    unsigned int size(){
        return cont.size();
    }

    // Checks to see if empty
    bool isEmpty(){
        if(cont.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }

private:
    doublyLinkedList<T> cont;
};

#endif
