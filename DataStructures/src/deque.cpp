#include <iostream>
#include "deque.h"

#define BOX_SIZE 10

Deque::box::box() :
    m_data(BOX_SIZE),
    m_begin(BOX_SIZE/2),
    m_end(BOX_SIZE/2)
{
}

Deque::Deque():
    box_map(BOX_SIZE),
    m_begin(BOX_SIZE/2),
    m_end(BOX_SIZE/2)
{
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
}

void Deque::push_back( int value )
{
    if ( m_begin == m_end )//It means map is empty
    {
        box_map[m_end++] = new box;
    }

    //TODO need to write when map is full

    if( box_map[m_end-1]->m_end == BOX_SIZE )//It means last box is full from right
    {
        box_map[m_end++] = new box;
    } 
    box_map[m_end - 1]->m_data[box_map[m_end-1]->m_end] = value;
    box_map[m_end - 1]->m_end++;
}

void Deque::push_front( int value )
{
    if ( m_begin == m_end )//It means map is empty
    {
        box_map[m_begin--] = new box;
    }
    //TODO need to write when map is full
    if( box_map[m_begin]->m_begin == -1 )//It means first box is full from left
    {
        box_map[--m_begin] = new box;
    }
    box_map[m_begin]->m_data[(box_map[m_begin]->m_begin) -1] = value;
    box_map[m_begin]->m_begin--;
    /*if ( box_map.front()->m_begin == 0 )
    {
        box_map[--m_begin] = new box; 
    }
    box_map.front()->m_data[--(box_map.front()->m_begin)] = value;*/
}

void Deque::pop_back()
{
}

void Deque::pop_front()
{
}

size_t Deque::size() const
{
    size_t size = 0;
    for (int i = m_begin; i < m_end; ++i)
    {
        size += box_map[i]->m_end - box_map[i]->m_begin;
    }
    return size;
}

void Deque::print() const
{
    if (m_begin != m_end)
    {
    for (int i = m_begin; i < m_end; ++i)
    {
        std::cout << "Box " << i << ": ";
        for (int j = box_map[i]->m_begin; j < box_map[i]->m_end; ++j)
        {
            std::cout << box_map[i]->m_data[j] << " ";
        }
    }
    std::cout<<std::endl;
    }
    else
    {
        std::cout << "Deque is empty" << std::endl;
    }
}