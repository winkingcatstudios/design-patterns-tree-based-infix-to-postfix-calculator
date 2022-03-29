// -*- C++ -*-

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 //==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include "Array.h"
#include "Empty_Exception.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
	typedef T type;

	//
	// Queue default constructor
	//
	Queue(void);

	//
	// Queue copy constructor
	//
	Queue(const Queue& q);

	//
	// Queue destructor
	//
	~Queue(void);

	//
	// Queue assignment operator
	//
	const Queue& operator = (const Queue& rhs);

	//
	// Queue enqueue
	//
	void enqueue(T element);
	
	//
	// Queue dequeue
	//
	void dequeue(void);

	//
	// Queue dis empty
	//
	bool is_empty(void) const;

	//
	// Queue dsize
	//
	size_t size(void) const;

	//
	// Queue end
	//
	T end(void) const;

	//
	// Queue clear
	//
	void clear(void);

private:
	// add member variable here
	Array<T> arr_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
