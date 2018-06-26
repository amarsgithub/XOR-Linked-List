#include "LinkedList.h"

// Default Constructor
LinkedList::LinkedList()
{
    count = 0;
    head = nullptr;
}

LinkedList::Node::Node(int data)
{
    this->data = data;
    this->both = nullptr;
}

LinkedList::Node *LinkedList::xorCalc(Node *a, Node *b)
{
    return (Node*) ((uintptr_t) a ^ (uintptr_t) b);
}


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
        // tail->next = new Node();
        // tail->next->prev = tail;
        // tail = tail->next;
        newPtr->both = xorCalc(tail, nullptr);
        tail->both = xorCalc(newPtr, xorCalc(tail->both, nullptr));
        tail = newPtr;
    }

    count++;
}

LinkedList::Node *LinkedList::get(int index)
{

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
