//	Constructor
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack <int>& stack)
	:stack_(stack),
	add_(new Add_Command(stack)),
	subtract_(new Subtract_Command(stack)),
	multiply_(new Multiply_Command(stack)),
	divide_(new Divide_Command(stack)),
	mod_(new Mod_Command(stack))
{}

//	Destructor
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(void)
{
	delete add_; 
	delete subtract_; 
	delete multiply_;  
	delete divide_; 
	delete mod_; 
}

//	Create add command
Add_Command* Stack_Expr_Command_Factory::createAddCommand(void)
{
	return add_;
}

//	Creates subtract command
Subtract_Command* Stack_Expr_Command_Factory::createSubtractCommand(void)
{
	return subtract_;
}

//	Creates multiply command
Multiply_Command* Stack_Expr_Command_Factory::createMultiplyCommand(void)
{
	return multiply_;
}

//	Creates divide command
Divide_Command* Stack_Expr_Command_Factory::createDivideCommand(void)
{
	return divide_;
}

//	Creates mod command
Mod_Command* Stack_Expr_Command_Factory::createModCommand(void)
{
	return mod_;
}

//	Creates number command
Num_Command* Stack_Expr_Command_Factory::createNumCommand(int num)
{
	return new Num_Command(stack_, num);
}
