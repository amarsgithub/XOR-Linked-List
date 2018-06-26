#include "LinkedList.h"

int main(void)
{
    LinkedList myList;

    myList.add(5);
    myList.add(16);
    myList.add(17);

    myList.printList();

    // LinkedList::Node *someNode = myList.get(2);
    //
    // cout << someNode->data << endl;

    


    return 0;
}
