// Threads_for_two_functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

int fibonacci(int n)
{
    if ((n == 1) || (n == 0))
        return 1;
    
    //std::cout << (fibonacci(n - 1) + fibonacci(n - 2)) << " ";

    return (fibonacci(n - 1) + fibonacci(n - 2));
    
}

int factorial(int i)
{
    if (i == 0 || i == 1)
        return 1;

    //std::cout << (i * factorial(i - 1)) << " ";

    return (i * factorial(i - 1));
}

int main()
{
    std::thread th1(fibonacci, 5);
    th1.join();

    std::cout << std::endl;

    for (int i = 1; i < 6; ++i)
    {
        std::cout << fibonacci(i) << " ";
    }

    std::cout << std::endl;
   
    std::thread th2(factorial, 5);
    th2.join();

    std::cout << std::endl;

    for (int i = 1; i < 6; ++i)
    {
        std::cout << factorial(i) << " ";
    }

    return 0;
}

