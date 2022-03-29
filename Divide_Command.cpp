//	Constructor
Divide_Command::Divide_Command(Stack<int>& s)
	:s_(s)
{}

//	Pop top two numbers on stack, divide second to top by top, and push result to stack
void Divide_Command::execute(void)
{
	int num2 = s_.top();
	s_.pop();
	int num1 = s_.top();
	s_.pop();
	
	// Cannot divide by zero or the world will explode
	if (num2 == 0)
		throw std::logic_error("Invalid expression");
	else
		s_.push(num1 / num2);
}

// Precedence value of command
int Divide_Command::precedence(void)
{
	return 1;
}