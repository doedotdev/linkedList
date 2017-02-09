/*
Benjamin Horn
University of Cincinnati
Computer Science
MBA Data Science
*/

/*
Singly and Doubly Linked List Implementations
Headers File Listed below
#include "singlyLinkedList.h"
#include "doublyLinkedList.h"
*/

#include <iostream>
#include <cstdio>
#include "singlyLinkedList.h"
#include "doublyLinkedList.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    cout << "Linked List Program" << endl;
    cout << "Benjamin D. Horn | University of Cincinnati" << "\n \n \n" << endl;

    srand(time(NULL));

    // Singly Linked List Tests
    linkedList n; // create a list

    for (int i = 0; i < 5; i++){ // push back
        n.pushBack(rand() % 10 + 1);
    }

    for (int i = 0; i < 5; i++){ // push front
        n.pushFront(rand() % 10 + 1);
    }

    cout << "Display List: " << n.displayList() << endl;
    cout << "Size Quick: " << n.getSizeQuick() << endl;
    cout << "Traversal Size: " << n.getSizeWithTraversal() << endl;
    cout << "Display List: " << n.displayList() << endl;
    cout << "Display List: " << n.displayList() << endl;

    //Remove
    n.remove(0);
    cout << "Remove 0th item in list: " << endl;
    cout << "Display List: " << n.displayList() << endl;
    n.remove(5);
    cout << "Remove 5th item in list: " << endl;
    cout << "Display List: " << n.displayList() << endl;

    //Empty List handles
    cout << "/n/n/n Empty List Handles" << endl;

    linkedList x;
    cout << "Display List: " << x.displayList() << endl;
    cout << "Size Quick: " << x.getSizeQuick() << endl;
    cout << "Traversal Size: " << x.getSizeWithTraversal() << endl;
    cout << "Display List: " << x.displayList() << endl;
    cout << "Display List: " << x.displayList() << endl;

    //Remove
    n.remove(0);
    cout << "Remove 0th item in list: " << endl;
    cout << "Display List: " << x.displayList() << endl;
    n.remove(5);
    cout << "Remove 5th item in list: " << endl;
    cout << "Display List: " << x.displayList() << endl;



    // Doubly Linked List tests
    doublyLinkedList a;

    for (int i = 0; i < 5; i++){ // push back
        a.pushBack2(rand() % 10 + 1);
    }

    for (int i = 0; i < 5; i++){ // push front
        a.pushFront2(rand() % 10 + 1);
    }

    cout << "Display List Fwd: " << a.displayListFwd() << endl;
    cout << "Display List Bwd: " << a.displayListBwd() << endl;
    cout << "Size Quick: " << a.getSizeQuick2() << endl;
    cout << "Fwd Traversal Size: " << a.getSizeWithFwdTraversal() << endl;
    cout << "Bwd Traversal Size: " << a.getSizeWithBwdTraversal() << endl;

    //Remove
    a.remove2(0);
    cout << "Remove 0th item in list: " << endl;
    cout << "Display List Fwd: " << a.displayListFwd() << endl;
    cout << "Display List Bwd: " << a.displayListBwd() << endl;

    cout << "Size Quick: " << a.getSizeQuick2() << endl;
    cout << "Fwd Traversal Size: " << a.getSizeWithFwdTraversal() << endl;
    cout << "Bwd Traversal Size: " << a.getSizeWithBwdTraversal() << endl;

    a.remove2(5);
    cout << "Remove 5th item in list: " << endl;
    cout << "Display List Fwd: " << a.displayListFwd() << endl;
    cout << "Display List Bwd: " << a.displayListBwd() << endl;

    cout << "Size Quick: " << a.getSizeQuick2() << endl;
    cout << "Fwd Traversal Size: " << a.getSizeWithFwdTraversal() << endl;
    cout << "Bwd Traversal Size: " << a.getSizeWithBwdTraversal() << endl;

    getchar();

    return 0;
}