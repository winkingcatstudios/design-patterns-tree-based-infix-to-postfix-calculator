#pragma once
#include "Binary_Expr_Command.h"

//	Pop top two numbers on stack, divide second to top by top, and push result to stack
class Divide_Command : public Binary_Expr_Command
{
public:

	//	Constructor
	Divide_Command(Stack<int>& s);

	//	Execute
	virtual void execute(void);

	//	Precedence
	virtual int precedence(void);

private:
	Stack<int>& s_;
};

#include "Divide_Command.cpp"
