#include "LinkedList.h"

int main(void)
{
    LinkedList myList;

    // Spec 1 asked by google: add an element
    myList.add(5);
    myList.add(16);
    myList.add(17);

    myList.printList();

    // Spec 2 asked by Google: access an element at an index
    try {
        LinkedList::Node *someNode = myList.get(7);
        cout << someNode->data << endl;
    } catch (int e)
    {
        cout << "Error in accessing element." << endl;
    }




    return 0;
}
