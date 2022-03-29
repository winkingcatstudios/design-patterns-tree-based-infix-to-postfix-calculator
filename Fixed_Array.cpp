// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef FIXED_ARRAY_CPP
#define FIXED_ARRAY_CPP

#include <stdexcept>  

//
// Fixed_Array default constructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	:Array_Base<T>(N)
{

}

//
// Fixed_Array copy constructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
	:Array_Base<T>(N)
{
	for (int i = 0; i < N; i++)
		this[i] = arr[i];
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
	:Array_Base<T>(arr)
{
	// Fixed array size cannot be changed, throw logic exception from stdexcept
	throw std::logic_error("Cannot change fix array size");
}

//
// Fixed_Array initialization contructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	:Array_Base<T>(N,fill)
{

}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{

}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	for (int i = 0; i < N; i++)
		this->data_[i] = rhs.data_[i];
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	// Fixed array size cannot be changed, throw logic exception from stdexcept
	throw std::logic_error("Cannot change fix array size");
}

#endif // FIXED_ARRAY_CPP
