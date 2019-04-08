#include <iostream>
#include "Square.h"
#include "LinkedList.h"
#include <string>
using namespace std;

void printIsEmpty(LinkedList &list)
{
    if (list.isEmpty()) 
    {
        cout << "List is empty." << endl;
    }
    else
    {
        cout << "List is not empty." << endl;
        cout << "Size = " << list.size() << endl;
    }
}
int main()
{
    LinkedList list;
    Square s1(1,2,3);
    Square s2(2,3,4);
    Square s3(3,4,5);
    Square s4(4,5,6);
    printIsEmpty(list);
    cout << "Adding Items..." << endl;
    list.add( s1 );
    list.add( s2 );
    list.add( s3 );
    list.add( s4 );
    printIsEmpty(list);
    list.print();
    cout << "The 1st item in the list is: " << list.get(0) << endl;
    cout << "The 3rd item in the list is: " << list.get(2) << endl;
    cout << "Modifyiing List..." << endl;
    Square s5(5, 6, 7);
    list.set(1, s5);
    list.print();
    Square s6(6, 7, 8);
    Square s7(3, 4, 5);
    cout << "Square 6 found at loc " << list.find(s6) << endl;
    cout << "Square 7 found at loc " << list.find(s7) << endl;
    return 0;
        

}