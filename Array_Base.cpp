// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef ARRAY_BASE_CPP
#define ARRAY_BASE_CPP

#include <stdexcept>

//
// Default constructors
//
template <typename T>
Array_Base <T>::Array_Base(void)
    :data_(new T[10]),
    cur_size_(0),
    max_size_(0)
{

}

//
// Initializing constructor
//
template <typename T>
Array_Base <T>::Array_Base(size_t length)
    :data_(new T[length]),
    cur_size_(length),
    max_size_(length)
{

}

//
// Initializing constructor
//
template <typename T>
Array_Base <T>::Array_Base(size_t length, T fill)
    :data_(new T[length]),
    cur_size_(length),
    max_size_(length)
{
    for (int i = 0; i < length; i++)
        this->data_[i] = fill;
}

//
// Copy constructor
//
template <typename T>
Array_Base <T>::Array_Base(const Array_Base& array)
    :data_(new T[array.cur_size_]),
    cur_size_(array.cur_size_),
    max_size_(array.max_size_)
{
    for (int i = 0; i < array.cur_size_; i++)
        this->data_[i] = array.data_[i];
}

//
// Destructor
//
template <typename T>
Array_Base <T>::~Array_Base(void)
{
    delete[] this->data_;
}

//
// Index Operator []
//
template <typename T>
T& Array_Base <T>::operator [] (size_t index)
{
    if (index >= this->cur_size_)
        throw std::out_of_range("Out of range");
    else
        return this->data_[index];
}

template <typename T>
const T& Array_Base <T>::operator [] (size_t index) const
{
    if (index >= this->cur_size_)
        throw std::out_of_range("Out of range");
    else
        return this->data_[index];
}


//
// Getter
//
template <typename T>
T Array_Base <T>::get(size_t index) const
{
    if (index >= this->cur_size_)
        throw std::out_of_range("Out of range");
    else
        return this->data_[index];
}

//
// Setter
//
template <typename T>
void Array_Base <T>::set(size_t index, T value)
{
    if (index >= this->cur_size_)
        throw std::out_of_range("Out of range");
    else
        this->data_[index] = value;
}

//
// Finds element from starting position
//
template <typename T>
int Array_Base <T>::find(T value) const
{
    for (int i = 0; i < this->cur_size_; i++)
    {
        if (this->data_[i] == value)
            return i;
    }
    return -1;
}

//
// FInds element from given position
//
template <typename T>
int Array_Base <T>::find(T val, size_t start) const
{
    if (start >= this->cur_size_)
        throw std::out_of_range("Out of range");
    else
    {
        for (int i = start; i < this->cur_size_; i++)
        {
            if (this->data_[i] == val)
                return i;
        }
        return -1;
    }
}


//
// Equality operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base& rhs) const
{
    //test if both arrays point to the same place in memory
    if (this->data_ == rhs.data_)
        return true;

    if (this->cur_size_ == rhs.cur_size_)
    {
        for (int i = 0; i < this->cur_size_; i++)
        {
            if (this->data_[i] != rhs.data_[i])
                return false;
        }
        return true;
    }
    else
        return false;
}

//
// Inequality operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base& rhs) const
{
    if (this->cur_size_ == rhs.cur_size_)
    {
        int i = 0;
        while (this->data_[i] == rhs.data_[i])
        {
            if (i == this->cur_size_ - 1)
                return false;
            else
                i++;
        }
        return true;
    }
    else
        return true;
}

//
// Fills with element
//
template <typename T>
void Array_Base <T>::fill(T value)
{
    for (int i = 0; i < this->cur_size_; i++)
    {
        this->data_[i] = value;
    }
}

#endif