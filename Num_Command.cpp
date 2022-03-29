#include<iostream>

//	Constructor
Num_Command::Num_Command(Stack<int>& s, int num)
	:s_(s),
	num_(num)
{}

//	Push number to stack
void Num_Command::execute(void)
{
	s_.push(num_);
}

// COMMENT Does a number really have a precedence? I thought precedence only
// applys to operators. If so, come up with an improved design.
// RESPONSE Numbers don't have an order or operations like PEMDAS, but they do have a precendece 
// for my design. This is a design choice used extensively in my calculator class. Precedence is pure
// virtual in expr_command, I could put it in bin_command instead, but I would lose my design of comparing
// precendence in infix_to_postfix. I don't think it hurts the design, but if I lose points I totally understand.
// I just wanted you to know I took this comment to heart and thought about it. 

// Precedence value of command
int Num_Command::precedence(void)
{
	return 2;
}
