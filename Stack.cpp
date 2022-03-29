// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack default constructor
//
template <typename T>
Stack <T>::Stack(void)
// COMMENT There is no need to explicitly call the default constructor of
// an object contained in a class.
// RESPONSE Removed unnecessary default constructor call
	:arr_()
{

}

//
// Stack copy constructor
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
// COMMENT You are constructing a temp object just to call the copy constructor
// on the array class. Just write: arr_ (stack.arr_)
// RESPONSE Removed unnecessary temp object
	:arr_(stack.arr_)
{

}

//
// ~Stack destructor
//
template <typename T>
Stack <T>::~Stack (void)
{
	
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	// Push to stack: resize and add element
	this->arr_.resize(this->arr_.size()+ 1);
	this->arr_[this->arr_.size() - 1] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	// Remove if stack isn't empty
	if (is_empty())
		throw Empty_Exception("Stack is empty");
	else
		this->arr_.resize(this->arr_.size() - 1);
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    // COMMENT Always check for self-assignment first before continuing.
	// RESPONSE Checking for self-assignment first
	if (this == &rhs)
		return *this;

	// Make a copy of everything
	this->arr_.resize(rhs.arr_.size());
	for (int i = 0; i < this->arr_.size(); i++)
		this->arr_[i] = rhs.arr_[i];
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    // COMMENT Just reset the variables instead popping each element, which
    // is expensive.
	// RESPONSE Reset array to be more efficient
    
	// Reset array to clear it out
	this->arr_.resize(0);
}
