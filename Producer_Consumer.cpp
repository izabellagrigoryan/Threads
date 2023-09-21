// Producer_Consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

const int MAX_QUEUE_SIZE = 5;

std::queue<int> sharedQueue;
std::mutex mtx;
std::condition_variable cv;

void producer() 
{
    for (int i = 0; i < 10; ++i) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (sharedQueue.size() >= MAX_QUEUE_SIZE) 
            {
                std::cout << "Queue is full. Producer waiting...\n";
                cv.wait(lock, [] { return sharedQueue.size() < MAX_QUEUE_SIZE; });
            }
            sharedQueue.push(i);
            std::cout << "Produced: " << i << "\n";
        }

        cv.notify_all();
    }
}

void consumer() 
{
    for (int i = 0; i < 10; ++i) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (sharedQueue.empty()) 
            {
                std::cout << "Queue is empty. Consumer waiting...\n";
                cv.wait(lock, [] { return !sharedQueue.empty(); });
            }
            int data = sharedQueue.front();
            sharedQueue.pop();
            std::cout << "Consumed: " << data << "\n";
        }

        cv.notify_all();
    }
}

int main() 
{
    std::thread Producer(producer);
    std::thread Consumer(consumer);

    Producer.join();
    Consumer.join();

    return 0;
}