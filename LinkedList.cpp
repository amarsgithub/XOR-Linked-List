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


void LinkedList::add(Node *addNode)
{

}

LinkedList::Node *LinkedList::get(int index)
{

}

int LinkedList::getCount()
{
    return count;
}

// Operator overloads:
const int &LinkedList::operator[](unsigned int index) const
{

}

int & LinkedList::operator[](unsigned int index)
{

}

LinkedList &LinkedList::operator=(const LinkedList &rhs)
{

}

LinkedList::~LinkedList()
{

}
