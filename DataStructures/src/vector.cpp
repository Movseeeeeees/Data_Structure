#include "vector.h"
using namespace std;

// Constructor definition
Vector::Vector() 
{
    m_data = new int[1];
    m_back = m_data;
    m_storage_back = m_data + 1;
}

// Destructor definition
Vector::~Vector() 
{
    delete[] m_data;
}

Vector::Vector( Vector& other )// copy constructor  
{
    m_data = new int[other.capacity()];
    for( size_t i=0; i<other.size(); i++ )
    {
        m_data[i] = other.m_data[i];
    }
    m_back = m_data + other.size();
    m_storage_back = m_data + other.capacity();
}

Vector::Vector( Vector&& other )// move constructor
{
    m_data = other.m_data;
    m_back = other.m_back;
    m_storage_back = other.m_storage_back;
    other.m_data = nullptr;
    other.m_back = nullptr;
    other.m_storage_back = nullptr;
}

void Vector::push_back( int value )
{
    if( size() == capacity() )
    {
        int *tmp = new int[ size() * 2];
        for ( size_t i=0; i< size(); i++ )
        {
            tmp[i] = m_data[i];
        }
        int main_size = size();
        delete[] m_data;
        m_data = tmp;
        m_back = m_data + main_size;
        m_storage_back = m_data + main_size * 2; 
    }
    m_data[ size() ] = value;
    m_back++;
}

void Vector::pop_back()
{
    m_back--;
}

int& Vector::at( size_t index ) 
{
    if( index >= size() )
    {
        throw "Index out of range";
    }
    return m_data[index];
}

int Vector::operator[]( int index )
{
    return m_data[index];
}

int Vector::front()
{
    return m_data[0];
}

int Vector::back()
{
    return *(m_back-1);
}

size_t Vector::size()
{
    return m_back - m_data;    
}

size_t Vector::capacity()
{
    return m_storage_back - m_data;
}

bool Vector::empty()
{
    return 0 == size();
}

void Vector::reserve( size_t new_capacity )
{
    if( new_capacity <= capacity() )
    {
        return;
    }
    int *tmp = new int[ new_capacity ];
    for( size_t i=0; i<=size(); i++ )
    {
        tmp[i] = m_data[i];
    }
    int main_size = size();
    delete[] m_data;
    m_data = tmp;
    m_back = m_data + main_size;
    m_storage_back = m_data + new_capacity;
}

void Vector::shrink_to_fit()
{
    if( size() == capacity() )
    {
        return;
    }
    int *tmp = new int[ size() ];
    for( size_t i=0; i<=size(); i++ )
    {
        tmp[i] = m_data[i];
    }
    int main_size = size();
    delete[] m_data;
    m_data = tmp;
    m_back = m_data + main_size;
    m_storage_back = m_data + main_size;
}

void Vector::resize( size_t new_size )
{
    if( new_size > capacity() )
    {
        reserve(new_size);
    }
    for( size_t i=size(); i<new_size; i++ )
    {
        m_data[i] = 0;
    }
    m_back = m_data + new_size;
}

//Iterator class implementation

Vector::Iterator::Iterator( int * ptr ) 
:m_ptr(ptr) 
{
}

int& Vector::Iterator::operator*()
{
    return *m_ptr;
}

Vector::Iterator Vector::Iterator::operator++()
{
    m_ptr++;
    return *this;
}

Vector::Iterator Vector::Iterator::operator--()
{
    m_ptr--;
    return *this;
}

bool Vector::Iterator::operator!= ( const Iterator& other ) {
    return m_ptr != other.m_ptr;
}

Vector::Iterator Vector::begin()
{
    return Iterator(m_data);
}

Vector::Iterator Vector::end()
{
    return Iterator(m_back);
}

Vector::Iterator Vector::rbegin()
{
    return Iterator(m_back-1);
}

Vector::Iterator Vector::rend()
{
    return Iterator(m_data-1);
}

Vector& Vector::operator=( Vector& other )// copy assignment
{
    if( this == &other )
    {
        return *this;
    }
    delete[] m_data;
    m_data = new int[other.capacity()];
    for( size_t i=0; i<other.size(); i++ )
    {
        m_data[i] = other.m_data[i];
    }
    m_back = m_data + other.size();
    m_storage_back = m_data + other.capacity();
    return *this;
}

Vector& Vector::operator=( Vector&& other )// move assignment
{
    if( this == &other )
    {
        return *this;
    }
    delete[] m_data;
    m_data = other.m_data;
    m_back = other.m_back;
    m_storage_back = other.m_storage_back;
    other.m_data = nullptr;
    other.m_back = nullptr;
    other.m_storage_back = nullptr;
    return *this;
}

void Vector::clear()
{
    m_back = m_data;
}

void Vector::print()
{
    for( size_t i=0; i<size(); i++ )
    {
        cout << m_data[i] << " ";
    }
    cout<<endl;
}