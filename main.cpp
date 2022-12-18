#include <iostream>

#include "LinkedList.h"
using namespace std;




int main()
{
    LinkedList<int> myList, *myList2;
    myList.Add(3);
    myList.Add(5);
    myList.Add(7);
    myList.Add(9);
    myList.Add(11);


    myList.Display();
    myList.InsertAfter(40,9);

    myList.Display();

    return 0;
}
