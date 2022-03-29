#pragma once
#include "Binary_Expr_Command.h"

//	Pop top two numbers on stack, multiply them, and push result to stack
class Multiply_Command : public Binary_Expr_Command
{
public:

	//	Constructor
	Multiply_Command(Stack<int>& s);

	//	Execute
	virtual void execute(void);

	//	Precedence
	virtual int precedence(void);

private:
	Stack<int>& s_;
};

#include "Multiply_Command.cpp"
