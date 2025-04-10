#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;
class List
{
    struct Node
    {
        int data;
        Node *next;
        Node *previous;
        Node(int value, Node *next = nullptr, Node *previous = nullptr);
    };
    Node *head;
    Node *tail;
    int size;

public:
    List();
    ~List();
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    void insert(int index, int value);
    void erase(int index);
    void reverse();
    Node &front();
    Node &back();
    int get_size() const;
    bool is_empty() const;
    void print();

    class Iterator
    {
        Node *current;

    public:
        Iterator(Node *node) : current(node) {}
        Node &operator*();
        Iterator &operator++();
        Iterator &operator--();
        bool operator!=(const Iterator &other) const;

        friend class List;
    };

    void insert_after_iterator(Iterator it, int value);
    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();

    List &Merge(List &other);
    List &Splice(Iterator pos, List &other);
};

#endif // LIST_H