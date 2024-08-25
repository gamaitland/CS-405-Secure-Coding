// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class custom_exception : public std::exception {};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    //GM: Adding regular throw statement

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    throw std::exception("Some Exception");

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

  //GM: Adding try/catch
    try {
        if (do_even_more_custom_application_logic()) {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    //GM: Created a custom exception

    throw custom_exception();

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    //GM: using invalid_argument for divisions by zero


        if (den == 0) {
            throw std::invalid_argument("You cannot divide a number by 0.");
        }

    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.
    //GM: Wrapping division statements in try/catch

        float numerator = 10.0f;
        float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Division Error, Exception Caught: " << e.what() << std::endl;
    }
 
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    //GM: Last exception handler uses the ellipses which can catch all.

    try {
        do_division();
        do_custom_application_logic();
    }
    catch (const custom_exception& e) {
        std::cerr << "Custom Exception Caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception Caught: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Exception Caught: " << std::endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu