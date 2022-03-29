//	Constructor
Mod_Command::Mod_Command(Stack<int>& s)
	:s_(s)
{}

//	Pop top two numbers on stack, mod second to top by top, and push result to stack
void Mod_Command::execute(void)
{
	int num2 = s_.top();
	s_.pop();
	int num1 = s_.top();
	s_.pop();
	s_.push(num1 % num2);
}

// Precedence value of command
int Mod_Command::precedence(void)
{
	return 1;
}