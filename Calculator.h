#pragma once
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"
#include "Num_Command.h"
#include "Stack_Expr_Command_Factory.h"
#include "Stack.h"
#include "Queue.h"
#include <sstream>
#include <typeinfo>
#include <map>
#include <iostream>

// Calculator class
class Calculator
{
public:

	//	Constructor
	Calculator(void);

	//	Arapper facade interface
	void calc(std::string expr);

	//	Evalutates infix using parse, parentheses, and infix_to_postfix
	int evaluate(Array<std::string> infix);

	//	Parser
	Array<std::string> parse(std::string expr);

	//	Number check
	bool isNum(std::string str);

	//	Infix to Postfix
	Queue<Expr_Command*> infix_to_postfix(Array<Expr_Command*>& infix);

	//	Make commands
	Array<Expr_Command*> makeCommands(Array<std::string>& infix, Stack_Expr_Command_Factory& factory);
};

#include "Calculator.cpp"
