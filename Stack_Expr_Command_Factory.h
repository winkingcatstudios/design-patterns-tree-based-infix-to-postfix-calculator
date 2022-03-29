#pragma once
#include "Expr_Command_Factory.h"
#include "Stack.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
	//	Constructor
	Stack_Expr_Command_Factory(Stack <int>& stack);

	//	Destructor
	~Stack_Expr_Command_Factory(void);

	//	Creates add command
	virtual Add_Command* createAddCommand(void);

	// Creates subtract command
	virtual Subtract_Command* createSubtractCommand(void);

	// Creates multiply command
	virtual Multiply_Command* createMultiplyCommand(void);

	//	Creates divide command
	virtual Divide_Command* createDivideCommand(void);

	//	Creates mod command
	virtual Mod_Command* createModCommand(void);

	//	Creates num command
	virtual Num_Command* createNumCommand(int num);

private:
	Stack <int>& stack_;
	Add_Command* add_;
	Subtract_Command* subtract_;
	Multiply_Command* multiply_;
	Divide_Command* divide_;
	Mod_Command* mod_;
};

#include "Stack_Expr_Command_Factory.cpp"
