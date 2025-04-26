#include <iostream>
#include "deque.h"

#define BOX_SIZE 10

Deque::box::box() :
    m_data(BOX_SIZE),
    m_begin(-1),
    m_end(-1)
{
}

Deque::Deque():
    box_map(BOX_SIZE),
    m_begin(BOX_SIZE/2),
    m_end(BOX_SIZE/2)
{
    box_map[m_end] = new box;
}

Deque::Deque( std::initializer_list<int> list )
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        push_back(*it);
    }
}

Deque::~Deque()
{
    for (int i = m_begin; i <= m_end; ++i)
    {
        delete box_map[i];
    }
}

void Deque::push_back( int value )
{
    if ( m_end == BOX_SIZE )
    {
        std::vector<box*> new_box_map(BOX_SIZE * 2);
        for (int i = 0; i < BOX_SIZE; ++i)
        {
            new_box_map[i] = box_map[i];
        }   
        box_map = new_box_map;
    }
    if( box_map[m_end]->m_end + 1 == BOX_SIZE )//It means last box is full from right
    {
        box_map[++m_end] = new box;
    } 
    box_map[m_end]->m_data[++(box_map[m_end]->m_end)] = value;
    if ( box_map[m_end]->m_begin == -1 )
    {
        box_map[m_end]->m_begin = 0;
    }
}

void Deque::push_front( int value )
{
    if( box_map[m_begin]->m_begin == 0 )//It means first box is full from left
    {
        box_map[--m_begin] = new box;
    }
    if ( box_map[m_begin]->m_begin == -1 && box_map[m_begin]->m_end == -1 )
    {
        box_map[m_begin]->m_begin = BOX_SIZE ;
        box_map[m_begin]->m_end = BOX_SIZE - 1;
    }
    box_map[m_begin]->m_data[--(box_map[m_begin]->m_begin)] = value;
    if ( box_map[m_begin]->m_end == -1 )
    {
        box_map[m_begin]->m_end = 0;
    }
    //TODO need to write when map is full
}

void Deque::pop_back()
{
    if ( size() == 0 )
    {
        return;
    }
    box_map[m_end]->m_end--;
    if ( box_map[m_end]->m_end <= -1 )
    {
        delete box_map[m_end];
        box_map[m_end] = nullptr;
        --m_end;
    }
}

void Deque::pop_front()
{
    if ( size() == 0 )
    {
        return;
    }
    box_map[m_begin]->m_begin++;
    if ( box_map[m_begin]->m_begin == BOX_SIZE )
    {
        delete box_map[m_begin];
        box_map[m_begin] = nullptr;
        ++m_begin;
    }
}

int& Deque::front()
{
    if ( size() == 0 )
    {
        throw std::out_of_range("Deque is empty");
    }
    return box_map[m_begin]->m_data[box_map[m_begin]->m_begin];
}

int& Deque::back()
{
    if ( size() == 0 )
    {
        throw std::out_of_range("Deque is empty");
    }
    return box_map[m_end]->m_data[box_map[m_end]->m_end];
}

size_t Deque::size() const
{
    size_t size = 0;
    for (int i = m_begin; i <= m_end; ++i)
    {
        size += box_map[i]->m_end - box_map[i]->m_begin + 1;
    }
    return size;
}

bool Deque::empty() const
{
    return size() == 0;
}

void Deque::print() const
{
    for (int i = m_begin; i <= m_end; ++i)
    {
        std::cout << "Box " << i << ": ";
        for (int j = box_map[i]->m_begin; j <= box_map[i]->m_end; ++j)
        {
            std::cout << box_map[i]->m_data[j] << " ";
        }
    }
    std::cout<<std::endl;
}

Deque::IteratorDeque Deque::begin()
{
    //return IteratorDeque(this, m_begin, box_map[m_begin]->m_begin);
}

Deque::IteratorDeque Deque::end()
{
    //return IteratorDeque(this, m_end, box_map[m_end]->m_end);
}