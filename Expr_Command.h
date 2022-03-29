#pragma once
#include "Stack.h"

//	Base class for commands
class Expr_Command 
{
public:
	
	// Execute
	virtual void execute (void) = 0;

	//	Precedence
	virtual int precedence (void) = 0;
};