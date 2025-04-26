#include <iostream>
#include "vector.h"
#include "list.h"
#include "deque.h"

using namespace std;

void check_list()
{
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
}

int main() {
    Deque deque;

    
    
    for (int i = 0; i < 5; ++i) {
        deque.push_front(i);
    }
    cout << "Deque after push_front: ";
    deque.print();

    cout << "Size of deque: " << deque.size() << endl;

    for (int i = 0; i < 12; ++i) {
        deque.push_back(i);
    }
    cout << "Deque after push_back: ";
    deque.print();
    cout << "Size of deque: " << deque.size() << endl;
    
    deque.pop_back();
    deque.pop_back();

    cout << "Deque after pop_back: ";
    deque.print();
    
    deque.pop_front();
    deque.pop_front();
    cout << "Deque after pop_front: ";
    deque.print();
    cout << "Size of deque: " << deque.size() << endl;
    return 0;
}