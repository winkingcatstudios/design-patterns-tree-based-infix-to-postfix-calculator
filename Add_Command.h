#pragma once
#include "Binary_Expr_Command.h"

//	Pop top two numbers on stack, add them, and push result to stack
class Add_Command : public Binary_Expr_Command
{
public:

	//	Constructor
	Add_Command(Stack<int>& s);

	//	Execute
	virtual void execute(void);

	//	Precedence
	virtual int precedence(void);

private:
	Stack<int>& s_;
};

#include "Add_Command.cpp"