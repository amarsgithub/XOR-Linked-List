#include "LinkedList.h"

// Default Linked list constructor
LinkedList::LinkedList()
{
    count = 0;
    head = nullptr;
}

// Node constructor
LinkedList::Node::Node(int data)
{
    this->data = data;
    this->both = nullptr;
}

// Probably the main code of the program: calculates the xor between two
// addresses of two Nodes.
LinkedList::Node *LinkedList::xorCalc(Node *a, Node *b)
{
    return (Node*) ((uintptr_t) a ^ (uintptr_t) b);
}

// Adds a node at either the head or the tail
void LinkedList::add(int data)
{
    Node *temp = head;
    Node *newPtr = new Node(data);
    if (head == nullptr)
    {
        head = tail = newPtr;
    }
    else
    {
        newPtr->both = xorCalc(tail, nullptr);
        tail->both = xorCalc(newPtr, xorCalc(tail->both, nullptr));
        tail = newPtr;
    }

    count++;
}

int LinkedList::getCount()
{
    return count;
}

// Goes through list iteratively and prints each node
void LinkedList::printList()
{
    Node *curr = head;
    Node *prev = nullptr, *next = nullptr;

    while(curr != nullptr)
    {
        cout << curr->data << endl;
        next = xorCalc(prev, curr->both);
        prev = curr;
        curr = next;

    }
}

void LinkedList::printListReverse()
{
    Node *curr = tail;
    Node *prev = nullptr, *next = nullptr;

    while (curr != nullptr)
    {
        cout << curr->data << endl;
        next = xorCalc(prev, curr->both);
        prev = curr;
        curr = next;
    }
}

// Retuns a node at an index
LinkedList::Node *LinkedList::get(int index)
{
    Node *curr = head;
    Node *prev = nullptr, *next = nullptr;

    if (index > count)
        throw -1;

    for (int i = 0; i < index; i++)
    {
        next = xorCalc(prev, curr->both);
        prev = curr;
        curr = next;
    }
    return curr;
}

int & LinkedList::operator[](unsigned int index)
{
    Node *curr = head;
    Node *prev = nullptr, *next = nullptr;

    if (index > count)
        throw -1;

    for (int i = 0; i < index; i++)
    {
        next = xorCalc(prev, curr->both);
        prev = curr;
        curr = next;
    }
    return curr->data;
}



// Goes through list iteratively and deletes all of the nodes
LinkedList::~LinkedList()
{
    Node *curr = head;
    Node *prev = nullptr, *next = nullptr;

    if (head == nullptr)
        return;

    while(curr != nullptr)
    {
        next = xorCalc(prev, curr->both);
        prev = curr;
        delete curr;
        curr = next;
    }

}
