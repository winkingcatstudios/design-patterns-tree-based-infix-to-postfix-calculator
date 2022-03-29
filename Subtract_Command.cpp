//	Constructor
Subtract_Command::Subtract_Command(Stack<int>& s)
	:s_(s)
{}

//	Pop top two numbers on stack, subract top from second to top, and push result to stack
void Subtract_Command::execute(void)
{
	int num2 = s_.top();
	s_.pop();
	int num1 = s_.top();
	s_.pop();
	s_.push(num1 - num2);
}

// Precedence value of command
int Subtract_Command::precedence(void)
{
	return 0;
}