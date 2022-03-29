#pragma once
#include "Expr_Command.h"

//	Push number to stack
class Num_Command : public Expr_Command
{
public:

	//	Constructor
	Num_Command(Stack<int>& s, int num);

	//	Execute
	virtual void execute(void);

	//	Precedence
	virtual int precedence(void);

private:
	Stack<int>& s_;
	int num_;
};

#include "Num_Command.cpp"

