#pragma once
#include "Binary_Expr_Command.h"

//	Pop top two numbers on stack, subract top from second to top, and push result to stack
class Subtract_Command : public Binary_Expr_Command
{
public:

	//	Constructor
	Subtract_Command(Stack<int>& s);

	//	Execute
	virtual void execute(void);

	//	Precedence
	virtual int precedence(void);

private:
	Stack<int>& s_;
};

#include "Subtract_Command.cpp"
