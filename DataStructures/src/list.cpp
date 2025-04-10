#include "list.h"

List::Node::Node(int value,
                 Node *next,
                 Node *previous)
{
    data = value;
    this->next = next;
    this->previous = previous;
}

List::List() : head(nullptr),
               tail(nullptr),
               size(0)
{
}

List::~List()
{
    /*while (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }*/
}

void List::push_back(int value)
{
    Node *newNode = new Node(value);
    if (!tail)
    {
        head = newNode; // It means list is empty
    }
    else
    {
        tail->next = newNode;
    }
    newNode->previous = tail;
    tail = newNode;
    size++;
}

void List::push_front(int value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        tail = newNode; // It means list is empty
    }
    else
    {
        head->previous = newNode;
        newNode->next = head;
    }
    head = newNode;
    size++;
}

void List::pop_back()
{
    if (tail)
    {
        if (tail->previous)
        {
            Node *tmpNode = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete tmpNode;
        }
        else
        {
            delete tail;
            tail = nullptr;
            head = nullptr;
        }
        size--;
    }
}

void List::pop_front()
{
    if (head)
    {
        if (head->next)
        {
            Node *tmpNode = head;
            head = head->next;
            head->previous = nullptr;
            delete tmpNode;
        }
        else
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        size--;
    }
}

void List::insert(int index, int value)
{
    if (index < size)
    {
        Iterator it = head;
        for (int tmpIndex = 0; it != tail; ++it, tmpIndex++)
        {
            if (index == tmpIndex)
            {
                break;
            }
        }
        Node *tmpNode = new Node(value);
        (*it).previous->next = tmpNode;
        tmpNode->previous = (*it).previous;
        (*it).previous = tmpNode;
        tmpNode->next = it.current;
        size++;
    }
}

void List::erase(int index)
{
    if (index < size)
    {
        Iterator it = head;
        for (int tmpIndex = 0; it != tail; ++it, tmpIndex++)
        {
            if (index == tmpIndex)
            {
                break;
            }
        }
        if (it.current->next)
        {
            Node *tmpNodeNext = it.current->next;
            Node *tmpNodePrevious = it.current->previous;
            tmpNodePrevious->next = tmpNodeNext;
            tmpNodeNext->previous = tmpNodePrevious;
        }
        else
        {
            it.current->previous->next = nullptr;
        }
        delete it.current;
        size--;
    }
}

void List::reverse()
{
    Iterator itBegin = begin();
    Iterator itEnd = rbegin();
    for (int count = 0, tmp; count <= size / 2; ++itBegin, --itEnd, count++)
    {
        tmp = itBegin.current->data;
        itBegin.current->data = itEnd.current->data;
        itEnd.current->data = tmp;
    }
}

List::Node &List::front()
{
    return *head;
}

List::Node &List::back()
{
    return *tail;
}

int List::get_size() const
{
    return size;
}

bool List::is_empty() const
{
    return !head;
}

void List::print() 
{
    Iterator tmpNodeBegin = begin();
    Iterator tmpNodeEnd = end();
    cout << "List: ";
    for (; tmpNodeBegin != tmpNodeEnd; ++tmpNodeBegin)
    {
        cout << tmpNodeBegin.current->data << " ";
    }
    cout << endl;
}

void List::insert_after_iterator(Iterator it, int value)
{
    Node *tmpNode = new Node(value);
    if (it.current->next != nullptr)
    {
        tmpNode->next = it.current->next;
        tmpNode->next->previous = tmpNode;
    }
    it.current->next = tmpNode;
    tmpNode->previous = it.current;
    size++;
}

List::Node &List::Iterator::operator*()
{
    return *current;
}

List::Iterator &List::Iterator::operator++()
{
    current = current->next;
    return *this;
}

List::Iterator &List::Iterator::operator--()
{
    current = current->previous;
    return *this;
}

bool List::Iterator::operator!=(const Iterator &other) const
{
    return other.current != this->current;
}

List::Iterator List::begin()
{
    return Iterator(head);
}

List::Iterator List::end()
{
    return Iterator(nullptr);
}

List::Iterator List::rbegin()
{
    return Iterator(tail);
}

List::Iterator List::rend()
{
    return Iterator(nullptr);
}

List &List::Merge(List &other)
{
        if (tail)
    {
        if (other.head)
        {
            tail->next = other.head;
            other.head->previous = tail;
            tail = other.tail;
            size += other.size;
        }
    }
    else
    {
        head = other.head;
        tail = other.tail;
        size = other.size;
    }

    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;

    return *this;
}

List &List::Splice(Iterator pos, List &other)
{
    if (!other.head)
    {
        return *this;
    } 
    Node *tmp = pos.current->next;
    pos.current->next = other.head;
    other.head->previous = pos.current;
    other.tail->next = tmp;
    if(tmp)
    {
        tmp->previous = other.tail;
    }
    else 
    {
        tail = other.tail;
    }
    size += other.size;

    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;

    return *this;
}