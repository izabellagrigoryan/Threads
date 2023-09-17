// 20_threads_for_one_function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>

int fibonacci(int n)
{
    std::mutex my_mutex;
    std::unique_lock<std::mutex> my_mutex_lock(my_mutex);

        my_mutex_lock.unlock();
        if ((n == 1) || (n == 0))
        {
            my_mutex_lock.lock();
            return 1;
        }

        int fib = (fibonacci(n - 1) + fibonacci(n - 2));
    
    return fib;
}

int main()
{
        std::thread th1(fibonacci, 1);
        th1.join();
        std::cout << fibonacci(1) << " ";
        std::thread th2(fibonacci, 2);
        th2.join();
        std::cout << fibonacci(2) << " ";
        std::thread th3(fibonacci, 3);
        th3.join();
        std::cout << fibonacci(3) << " ";
        std::thread th4(fibonacci, 4);
        th4.join();
        std::cout << fibonacci(4) << " ";
        std::thread th5(fibonacci, 5);
        th5.join();
        std::cout << fibonacci(5) << " ";
        std::thread th6(fibonacci, 6);
        th6.join();
        std::cout << fibonacci(6) << " ";
        std::thread th7(fibonacci, 7);
        th7.join();
        std::cout << fibonacci(7) << " ";
        std::thread th8(fibonacci, 8);
        th8.join();
        std::cout << fibonacci(8) << " ";
        std::thread th9(fibonacci, 9);
        th9.join();
        std::cout << fibonacci(9) << " ";
        std::thread th10(fibonacci, 10);
        th10.join();
        std::cout << fibonacci(10) << " ";
        std::thread th11(fibonacci, 11);
        th11.join();
        std::cout << fibonacci(11) << " ";
        std::thread th12(fibonacci, 12);
        th12.join();
        std::cout << fibonacci(12) << " ";
        std::thread th13(fibonacci, 13);
        th13.join();
        std::cout << fibonacci(13) << " ";
        std::thread th14(fibonacci, 14);
        th14.join();
        std::cout << fibonacci(14) << " ";
        std::thread th15(fibonacci, 15);
        th15.join();
        std::cout << fibonacci(15) << " ";
        std::thread th16(fibonacci, 16);
        th16.join();
        std::cout << fibonacci(16) << " ";
        std::thread th17(fibonacci, 17);
        th17.join();
        std::cout << fibonacci(17) << " ";
        std::thread th18(fibonacci, 18);
        th18.join();
        std::cout << fibonacci(18) << " ";
        std::thread th19(fibonacci, 19);
        th19.join();
        std::cout << fibonacci(19) << " ";
        std::thread th20(fibonacci, 20);
        th20.join();
        std::cout << fibonacci(20) << " ";
}

