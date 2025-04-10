#include <iostream>
#include "vector.h"
#include "list.h"
using namespace std;

int main() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    cout << "List size: " << list.get_size() << endl;
    list.print();

    list.pop_back();
    list.print();

    list.pop_front();
    list.print();

    list.reverse();
    list.print();

    list.insert(2, 10);
    list.print();

    list.erase(2);
    list.print();

    List list2;
    list2.push_front(6);
    list2.push_front(7);
    list2.Merge(list);
    cout << "List2 after merge: ";
    list2.print();

    List list3;
    list3.push_back(1);
    list3.push_back(4);

    list2.Splice(list2.begin(), list3);
    cout << "List2 after splice: ";
    list2.print();

    list2.reverse();
    list2.print();

    return 0;
}