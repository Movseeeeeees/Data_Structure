#include <vector>
#include <initializer_list>

#pragma once

class Deque
{
    class box 
    {
        friend class Deque;
        std::vector<int> m_data;
        int m_begin;
        int m_end;
    public:
        box();
    };
    std::vector<box*> box_map;
    int m_begin;
    int m_end; 
public:
    Deque();
    Deque( std::initializer_list<int> list );
    ~Deque();

    void push_back( int value );
    void push_front( int value );
    void pop_back();
    void pop_front();

    int& operator[]( size_t index );
    int& at( size_t index );
    int& front();
    int& back();
    size_t size() const;
    bool empty() const;
    void print() const;
    void printViaIterator() const;
    class IteratorDeque
    {
        friend class Deque;
        Deque* m_deque;
        int m_box_index;
        int m_element_index;
    public:
        IteratorDeque( Deque* deque, int box_index, int element_index ); 
        IteratorDeque& operator++();
        IteratorDeque& operator--();
        bool operator!=( const IteratorDeque& other ); 
        int& operator*();
        int& operator[]( size_t index );
        void moveToNextBox();
        void moveToPrevBox();
    };
    IteratorDeque begin() const;
    IteratorDeque end() const;
};