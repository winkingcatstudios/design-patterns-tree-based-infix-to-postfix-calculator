#pragma once
#include "Expr_Command.h"

class Binary_Expr_Command : public Expr_Command 
{
public:

	//	Execute
	virtual void execute(void) = 0;

	//	Precedence
	virtual int precedence(void) = 0;
};
