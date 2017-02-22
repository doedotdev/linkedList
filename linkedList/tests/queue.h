//
// Created by Benjamin D. Horn on 2/22/17.
//

#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

#include <ostream>
#include <stdexcept>

#include "doublyLinkedList.h"

using namespace std;

template <class T>
class queue{

// Fill me in!
public:
    // Constructor
    queue(){
        doublyLinkedList<T> cont;
    }

    // Destructor
    ~queue(){
        cont.clear();
    }

    // Copy Constructor
    queue(const queue& other){
        this->cont = other.cont;
    }

    // Assignment Overload
    queue<T>& operator= (const queue& other){
        cont = other.cont;
    }

    // Place value at end of queue
    void enqueue(T value){
        cont.push_back(value);
    }

    // Remove front of queue
    void dequeue(){
        if(cont.size() != 0){
            cont.remove(0);
        }
    }

    // Return front of queue
    T front(){
        if(cont.size() == 0){
            throw logic_error("No queue!");
        }
        return cont.getAt(0);
    }

    // Return size
    unsigned int size(){
        return cont.size();
    }

    // Check to see if queue is empty
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

#endif //LINKEDLIST_QUEUE_H
