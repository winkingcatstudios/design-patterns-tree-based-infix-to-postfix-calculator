// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>

template <typename T>
class Array_Base
{
public:

	// Default constructor
	Array_Base(void);

	// Initializing constructor
	Array_Base(size_t length);

	// Initializing constructor.
	Array_Base(size_t length, T fill);

	// Copy constructor
	Array_Base(const Array_Base& array);

	// Destructor
	~Array_Base(void);

	// Index Operator []
	T& operator [] (size_t index);
	const T& operator [] (size_t index) const;
	
	// Retreive size
	size_t size(void) const;

	// Retreice max size
	size_t max_size(void) const;

	// Getter
	T get(size_t index) const;

	// Setter
	void set(size_t index, T value);

	// Finds element from starting position
	int find(T element) const;

	// FInds element from given position
	int find(T element, size_t start) const;

	// Equality operator ==
	bool operator == (const Array_Base& rhs) const;

	// Inequality operator !=
	bool operator != (const Array_Base& rhs) const;

	// Fills with element
	void fill(T element);


protected:
	// Pointer to the actual data.
	T* data_;

	// Current size of the array.
	size_t cur_size_;

	// Maximum size of the array.
	size_t max_size_;
};

#include "Array_Base.cpp"
#include "Array_Base.inl"

#endif   // !defined _ARRAY_BASE_H_