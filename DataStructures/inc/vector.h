#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
public:
    Vector();//constructor declaration
    ~Vector();//destructor declaration
    Vector( Vector& other );//copy constructor
    Vector( Vector&& other );//move constructor
    void push_back( int value );
    void pop_back();
    int& at( size_t index );
    int operator[]( int index );
    int front();
    int back();
    size_t size();
    size_t capacity();
    bool empty();
    void reserve( size_t new_capacity );
    void shrink_to_fit();//means to reduce the capacity of the vector to fit its size
    void resize( size_t new_size );

    class Iterator 
    {
        private:
            int* m_ptr;
        public:
            Iterator( int *ptr );//constructor
            int& operator*();//dereference operator to get the value
            Iterator operator++();//prefix increment operator
            Iterator operator--();//prefix decrement operator
            bool operator!= (const Iterator& other);//not equal operator
    };
    Iterator begin();//begin iterator
    Iterator end();//end iterator
    Iterator rbegin();//reverse begin iterator
    Iterator rend();//reverse end iterator

    Vector& operator=( Vector& other );//copy assignment
    Vector& operator=( Vector&& other );//move assignment

    void clear();
    void print();
private:
    int* m_data;
    int* m_back;
    int* m_storage_back;
};

#endif // VECTOR_H