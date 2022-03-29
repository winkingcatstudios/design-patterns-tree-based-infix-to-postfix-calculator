#pragma once
#include "Binary_Expr_Command.h"

//	Pop top two numbers on stack, mod second to top by top, and push result to stack
class Mod_Command : public Binary_Expr_Command
{
public:

	//	Constructor
	Mod_Command(Stack<int>& s);

	//	Execute
	virtual void execute(void);

	//	Precedence
	virtual int precedence(void);

private:
	Stack<int>& s_;
};

#include "Mod_Command.cpp"
