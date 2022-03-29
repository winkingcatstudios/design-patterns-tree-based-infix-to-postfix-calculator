// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// Queue size
//
template <typename T>
inline
size_t Queue <T>::size(void) const
{
	return this->arr_.size();
}

//
// Queue end
//
template <typename T> 
inline
T Queue<T>::end(void) const
{
	if (this->is_empty())
	{
		throw Empty_Exception("Queue is empty");
	}
	else
	{
		return this->arr_[this->size() - 1];
	}
}

//
// Queue is empty
//
template <typename T>
inline
bool Queue <T>::is_empty(void) const
{
	return this->size() == 0;
}