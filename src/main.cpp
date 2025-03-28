#include <iostream>
#include "vector.h"
using namespace std; 

int main() {
    cout << "Hello, World!" << endl;
    Vector v;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty: " << v.empty() << endl;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty: " << v.empty() << endl;
    v.print();
    v.pop_back();
    v.print();
    v.reserve(10);
    cout << "size: " << v.size() << endl;       
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty: " << v.empty() << endl;
    v.push_back(1);
    v.shrink_to_fit();
    cout << "size: " << v.size() << endl;   
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty: " << v.empty() << endl;
    v.resize(5);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty: " << v.empty() << endl;
    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for( Vector::Iterator it = v.begin(); it != v.end(); ++it )
    {
        cout << *it << " ";
    }
    cout << endl;
    for( auto it = v.rbegin(); it != v.rend(); --it )
    {
        cout << *it << " ";
    }
    cout << endl;

    Vector v2 = v;// copy assignment
    Vector v3( v2 );// copy constructor

    v3.at(0) = 1;
    cout << v3[0] << endl;
    v3.print();

    Vector v4 = std::move(v3);// move assignment
    Vector v5( std::move(v4) );// move constructor
    
    return 0;
}