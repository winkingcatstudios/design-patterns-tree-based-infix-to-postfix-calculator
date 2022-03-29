#pragma once
#include "Stack.h"

class Expr_Command_Factory
{
public:

	//	Creates add command
	virtual Add_Command* createAddCommand(void) = 0;

	//	Creates subtract command
	virtual Subtract_Command* createSubtractCommand(void) = 0;

	//	Creates multiply command
	virtual Multiply_Command* createMultiplyCommand(void) = 0;

	//	Creates divide command
	virtual Divide_Command* createDivideCommand(void) = 0;

	//	Creates mod command
	virtual Mod_Command* createModCommand(void) = 0;

	//	Creates num command
	virtual Num_Command* createNumCommand(int num) = 0;
};
