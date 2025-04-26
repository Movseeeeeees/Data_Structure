#include <iostream>
#include <cassert>
#include "../inc/deque.h"

void test_push_back() {
    Deque deque;

    deque.push_back(10);
    assert(deque.size() == 1);
    assert(deque.front() == 10);
    assert(deque.back() == 10);

    deque.push_back(20);
    deque.push_back(30);
    deque.push_back(40);
    assert(deque.size() == 4);
    assert(deque.front() == 10);
    assert(deque.back() == 40);

    for (int i = 50; i <= 100; i += 10) {
        deque.push_back(i);
    }
    assert(deque.size() == 10);
    assert(deque.front() == 10);
    assert(deque.back() == 100);

    std::cout << "All push_back tests passed!" << std::endl;
}

int main() {
    test_push_back();
    return 0;
}
