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
    if( box_map[m_end]->m_end + 1 == BOX_SIZE )
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
    if ( m_begin == 0 && box_map[m_begin]->m_begin == 0 )
    {
        std::vector<box*> new_box_map(BOX_SIZE * 2);
        for (int i = 0; i < BOX_SIZE; ++i)
        {
            new_box_map[i + BOX_SIZE] = box_map[i];
        }   
        box_map = new_box_map;
    }

    if( box_map[m_begin]->m_begin == 0 )
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

int& Deque::operator[](size_t index)
{
    size_t global_start = box_map[m_begin]->m_begin;
    size_t global_index = global_start + index;

    size_t box_index = m_begin + (global_index / BOX_SIZE);
    size_t position_in_box = global_index % BOX_SIZE;

    return box_map[box_index]->m_data[position_in_box];
}

int& Deque::at(size_t index)
{
    if (index >= size())
    {
        throw std::out_of_range("Index out of range");
    }
    return (*this)[index];
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

void Deque::printViaIterator() const
{
    for (Deque::IteratorDeque it = begin(); it != end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

Deque::IteratorDeque::IteratorDeque(Deque* deque, int box_index, int element_index) :
    m_deque(deque),
    m_box_index(box_index),
    m_element_index(element_index)
{
}

Deque::IteratorDeque& Deque::IteratorDeque::operator++()
{
    ++m_element_index;
    if (m_element_index > m_deque->box_map[m_box_index]->m_end)
    {
        if (m_box_index < m_deque->m_end)
        {
            moveToNextBox();
        }
        else
        {
            m_element_index = m_deque->box_map[m_box_index]->m_end + 1;
        }
    }
    return *this;
}

Deque::IteratorDeque& Deque::IteratorDeque::operator--()
{
    --m_element_index;
    if (m_element_index < m_deque->box_map[m_box_index]->m_begin)
    {
        if (m_box_index > m_deque->m_begin)
        {
            moveToPrevBox();
        }
        else
        {
            m_element_index = m_deque->box_map[m_box_index]->m_begin;
        }
    }
    return *this;
}

bool Deque::IteratorDeque::operator!=(const IteratorDeque& other)
{
    return m_box_index != other.m_box_index || m_element_index != other.m_element_index;
}

int& Deque::IteratorDeque::operator*()
{
    return m_deque->box_map[m_box_index]->m_data[m_element_index];
}

int& Deque::IteratorDeque::operator[]( size_t index )
{
    return m_deque->operator[](index);
}

void Deque::IteratorDeque::moveToNextBox()
{
    ++m_box_index;
    m_element_index = m_deque->box_map[m_box_index]->m_begin;
}

void Deque::IteratorDeque::moveToPrevBox()
{
    --m_box_index;
    m_element_index = m_deque->box_map[m_box_index]->m_end;
}

Deque::IteratorDeque Deque::begin() const
{
    return IteratorDeque(const_cast<Deque*>(this), m_begin, box_map[m_begin]->m_begin);
}

Deque::IteratorDeque Deque::end() const
{
    return IteratorDeque(const_cast<Deque*>(this), m_end, box_map[m_end]->m_end + 1);
}

