#pragma once

#include <iostream>
using namespace std;

class LinkedList
{
public:

    // This node contains data and the XOR between the previous and next nodes
    struct Node
    {
        int data;
        Node *both;
        Node(int data);
    };

    // Mutators:
    void add(int data);

    // Accessors:
    Node *get(int index);
    int getCount();

    // Constructor:
    LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList &rhs);

    // Operator overloads:
    const int &operator[](unsigned int index) const;
    int & operator[](unsigned int index);
    LinkedList &operator=(const LinkedList &rhs);

    // Print list:
    void printList();
    void printListReverse();

    // Destructor
    ~LinkedList();

private:
    Node *head;
    Node *tail;
    int count;
    void Set(const LinkedList &other);
    Node *xorCalc(Node *a, Node *b);
};
