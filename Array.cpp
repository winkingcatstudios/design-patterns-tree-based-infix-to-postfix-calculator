// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array default constructor
//
template <typename T>
Array <T>::Array (void)
	:Array_Base<T>(0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
	:Array_Base<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
	:Array_Base<T>(length, fill)
{

}

//
// Array (const Array &) copy constructor 
//
template <typename T>
Array <T>::Array (const Array & array)
	:Array_Base<T>(array.cur_size_)
{
	for (int i = 0; i < array.cur_size_; i++)
		this->data_[i] = array.data_[i];
}

//
// ~Array destructor
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this->data_ == rhs.data_)
		return *this;
	// Only change allocation is array isn't large enough, check here
	else 
	{
		if (this->cur_size_ >= rhs.cur_size_)
		{
			this->fill(0);
			for (int i = 0; i < rhs.cur_size_; i++)
				this->data_[i] = rhs.data_[i];
		}
		else
		{
			T* copy = new T[rhs.cur_size_];
			for (int i = 0; i < rhs.cur_size_; i++)
				copy[i] = rhs.data_[i];
			T* copyHolder = copy;
			copy = this->data_;
			this->data_ = copyHolder;
			delete[] copy;
		}

		this->cur_size_ = rhs.cur_size_;
	}
	return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size <= this->max_size_)
		this->cur_size_ = new_size;
	else
	{
		T* resized = new T[new_size];
		for (int i = 0; i < this->cur_size_; i++)
			resized[i] = this->data_[i];
		T* resizedHolder = resized;
		resized = this->data_;
		this->data_ = resizedHolder;
		delete[] resized;
		this->cur_size_ = new_size;
		this->max_size_ = new_size;
	}
}

#endif	// ARRAY_CPP
