// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


//
//	Size
//
template <typename T>
inline
size_t Array_Base <T>::size(void) const
{
	return this->cur_size_;
}

//
// Max size
//
template <typename T>
inline
size_t Array_Base <T>::max_size(void) const
{
	return this->max_size_;
}