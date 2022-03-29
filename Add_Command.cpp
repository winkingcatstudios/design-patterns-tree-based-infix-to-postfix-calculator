//	Constructor
Add_Command::Add_Command(Stack<int>& s)
	:s_(s)
{}

//	Pop top two numbers on stack, add them, and push result to stack
void Add_Command::execute(void)
{
	int num2 = s_.top();
	s_.pop();
	int num1 = s_.top();
	s_.pop();
	s_.push(num1 + num2);
}

// Precedence value of command
int Add_Command::precedence(void)
{
	return 0;
}