Calculator::Calculator(void)
{}

// Wrapper facade interface to calculator. Combibed parser and evaluator and prints output
void Calculator::calc(std::string expression)
{
    // Parse input and display results
    Array<std::string> infix;
    infix = parse(expression);
    std::cout << "Result: " << evaluate(infix) << std::endl;
}

//  Handle parenthesese, create commands, infix to postfix, execute commands
int Calculator::evaluate(Array<std::string> infix)
{
    //  Handle parenthesis by checking them first, and making sure they are paired/valid
    int parenthesesPos = 0;
    while (parenthesesPos < infix.size())
    {
        if (infix[parenthesesPos] == "(")
        {
            // Track parentheses for pairs and nesting, and loop to find all parentheses
            int parenthesesCount = 0;
            int nextParentheses = parenthesesPos + 1;
            bool hasParentheses = true;

            while (hasParentheses)
            {
                if (infix[nextParentheses] == "(")
                {
                    parenthesesCount++;
                    nextParentheses++;
                }
                else if (infix[nextParentheses] == ")")
                {
                    if (parenthesesCount == 0)
                        hasParentheses = false;
                    else
                    {
                        parenthesesCount--;
                        nextParentheses++;
                    }
                }
                else
                    nextParentheses++;
                
                // No closing parentheses found for opening parentheses
                if (nextParentheses >= infix.size())
                    throw std::logic_error("Invalid expression");
            }

            //  Pull parentheses expressionss into their own array to evaluate seperately (first)
            Array<std::string> parenthesesExpression(nextParentheses - parenthesesPos - 1);
            int parenthesesIndex = 0;
            for (int i = parenthesesPos + 1; i < nextParentheses; i++)
            {
                parenthesesExpression[parenthesesIndex] = infix[i];
                parenthesesIndex++;
            }

            //  Evaluate parentheses first due to highest precedence since they are not a command type with a precendence method
            std::stringstream ss;
            ss << evaluate(parenthesesExpression);
            infix[parenthesesPos] = ss.str();

            //  Shift and resize infix once parentheses are evaluated out
            int shift = nextParentheses - parenthesesPos;
            int infixParenthesesindex = nextParentheses + 1;
            while (infixParenthesesindex < infix.size())
            {
                infix[infixParenthesesindex - shift] = infix[infixParenthesesindex];
                infixParenthesesindex++;
            }
            infix.resize(infix.size() - shift);
        }
        parenthesesPos++;
    }

    // Instatiate stack factory and results stack
    Stack<int> results;
    Stack_Expr_Command_Factory stackFactory(results);

    // Create commands from infix strings using stackFactory
    Array<Expr_Command*> infixCommands;
    infixCommands = makeCommands(infix, stackFactory);

    //  Convert infix commands to postfix commands
    Queue<Expr_Command*> postfixCommands;
    postfixCommands = infix_to_postfix(infixCommands);

    //  Evaluate commands at end of queue and store results on stack
    while (postfixCommands.size() > 0)
    {
        postfixCommands.end()->execute();
        postfixCommands.dequeue();
    }
    return results.top();
}

//  Turn input expression into infix tokens
Array<std::string> Calculator::parse(std::string expression)
{
    //  Stringstream variables
    Queue<std::string> tokenStream;
    std::stringstream ss(expression);
    std::string token;

    //  A single space deliniates the next token from input
    //  Note: this is not best practice, but works with this project's guidelines
    while (getline(ss, token, ' '))
        tokenStream.enqueue(token);

    //  Create infix array from parsed tokens
    Array<std::string> infix(tokenStream.size());
    for (int i = 0; i < infix.size(); i++)
    {
        infix[i] = tokenStream.end();
        tokenStream.dequeue();
    }
    return infix;
}

//  Check if a token is a number. 
//  All input other thatn these, operators, and "QUIT" will be treated as garbage input
bool Calculator::isNum(std::string str)
{
    // Check if the token starts with a number or a negative sign
    if (isdigit(str[0]) || str[0] == '-')
    {
        // Searches the string for the first character that does NOT match the arguments
        // If none are found, there are only numbers
        // THis is needed to allow multidigit numbers and filter out garbage like "5a"
        if (str.find_first_not_of("0123456789", 1) == std::string::npos)
            return true;
    }
    return false;
}

//  Infix to Postfix using Expr_Command precedence methods
Queue<Expr_Command*> Calculator::infix_to_postfix(Array<Expr_Command*>& infix)
{
    // Queue for postfix commands and starting index
    Queue<Expr_Command*> postfix;
    int index = 0;

    while (infix.size() > 0)
    {
        if (index < infix.size() - 1)
        {
            // Compare precendence of token with precendence of next token
            if (infix[index]->precedence() >= infix[index + 1]->precedence())
            {
                // Check if infix tokens have an operator between operands
                // Example: "2 2" is invalid
                if (infix[index + 1]->precedence() == 2)
                    throw std::logic_error("Invalid expression");
                else
                {
                    // If valid token expression, add to postfix and process next
                    postfix.enqueue(infix[index]);
                    for (int i = index; i < infix.size() - 1; i++)
                        infix[i] = infix[i + 1];
                    infix.resize(infix.size() - 1);
                    if (index > 0)
                        index--;
                }
            }
            else
                index++;
        }
        //  Sepcial case: nothing left to compare. Should be last token so add it to postfix
        else
        {
            postfix.enqueue(infix[index]);
            infix.resize(infix.size() - 1);
            if (index > 0)
                index--;
        }
    }
    return postfix;
}

Array<Expr_Command*> Calculator::makeCommands(Array<std::string>& infix, Stack_Expr_Command_Factory& stackFactory)
{
    //convert each string value into its corresponding command
    Array<Expr_Command*> infixCommands(infix.size());
    for (int i = 0; i < infix.size(); i++)
    {
        // Check tokens for operator type, then check for numbers. Everyone else is garbage. 
        // "QUIT" condition is handled by Driver since it could change
        std::string token = infix[i];
        if (token == "+")
            infixCommands[i] = stackFactory.createAddCommand();
        else if (token == "-")
            infixCommands[i] = stackFactory.createSubtractCommand();
        else if (token == "*")
            infixCommands[i] = stackFactory.createMultiplyCommand();
        else if (token == "/")
            infixCommands[i] = stackFactory.createDivideCommand();
        else if (token == "%")
            infixCommands[i] = stackFactory.createModCommand();
        else if (this->isNum(token))
        {
            //  string to int with stringstream after checking isNum
            int intToken;
            std::stringstream ss(token);
            ss >> intToken;

            infixCommands[i] = stackFactory.createNumCommand(intToken);
        }
        else
            throw std::logic_error("Invalid expression");
    }
    return infixCommands;
}
