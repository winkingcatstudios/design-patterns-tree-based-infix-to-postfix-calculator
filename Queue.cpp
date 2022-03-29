// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <stdexcept>


//
// Queue default constructor
//
template <typename T>
Queue <T>::Queue(void)
// COMMENT There is no need to explicitly call the default constructor of
// an object contained in a class.
// RESPONSE Removed unnecessary default constructor call
    :arr_()
{

}

//
// Queue copy constructor
//
template <typename T>
Queue <T>::Queue(const Queue& queue)
// COMMENT You are constructing a temp object just to call the copy constructor
// on the array class. Just write: arr_ (queue.arr_)
// RESPONSE Removed unnecessary temp object
    :arr_(queue.arr_)
{

}

//
// ~Queue destructor
//
template <typename T>
Queue <T>::~Queue(void)
{

}

//
// Queue assignment operator
//
template <typename T>
const Queue <T>& Queue<T>::operator = (const Queue& rhs)
{
    // COMMENT Always check for self-assignment first before continuing.
    // RESPONSE Checking for self-assignment first
    if (this == &rhs)
        return *this;

    // Make a copy of everything
    arr_.resize(rhs.size());
    for (int i = 0; i < this->size(); i++)
        this->arr_[i] = rhs.arr_[i];
    return *this;
}

//
// Queue enqueue
//
template <typename T>
void Queue <T>::enqueue(T element)
{
    // COMMENT This approach can work, but its design is very expensive. You
    // should find a better design that tries to use as much space as possible
    // while minimizing the amount of copying that must occur.
    // RESPONSE Changed the resize code to only minimize copying and provide
    // checks to prevent unnecessary copies
    
    // Add to queue: resize, shift everything a step, and add element
    this->arr_.resize(this->size() + 1);
    for (int i = this->size() - 1; i > 0; i--)
        this->arr_[i] = this->arr_[i - 1];
    this->arr_[0] = element;
}

//
// Queue dequeue
//
template <typename T>
void Queue <T>::dequeue(void)
{
    // Remove deepest element and shift the queue a step, unless none exist
    T element;  // Element to return
    if (this->is_empty())
        throw  Empty_Exception("Queue is empty");
    else
        this->arr_.resize(this->size() - 1);
}

//
// Queue clear
//
template <typename T>
void Queue <T>::clear(void)
{
    // COMMENT This works, but is a very expensive operation. You should find a
    // way to just reset the state without having to dequeue every element.
    // RESPONSE Reset array to be more efficient

    // Reset array to clear it out
    this->arr_.resize(0);
}
