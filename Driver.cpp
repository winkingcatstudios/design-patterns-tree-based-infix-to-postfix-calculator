#include <iostream>
#include "Calculator.h"

int main(int argc, char* argv[])
{
    // Input expression
    std::string expression;

    // Calculator instance
    Calculator calculator;

    // Run until user quits
    bool quit = false;
    while (!quit)
    {
        // COMMENT Make sure you are deleting the commands between expressions
        // or you will have a memory leak.
        // RESPONSE Deleting commands in factory destructor
        
        try 
        {
            //  User instructions, catch invalid expressions
            std::cout << "Enter an infix expression with spaces between " << std::endl 
                      << "each token or enter QUIT to quit: ";
            std::getline(std::cin, expression);

            // "QUIT" condition defined here as it is part of the project not the calculator
            if (expression == "QUIT")
                quit = true;
            else
                calculator.calc(expression);
        }
        catch (...)
        {
            // Catch all execptions from parser, paretheses, divide by zero, etc
            std::cout << "Invalid expression" << std::endl;
        }
    }
}
