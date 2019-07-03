#include <iostream>
#include <thread>

/***
 * Please run this program using C++11 
 * To compile with MinGW64 use: <gcc file.cpp> -lstdc++ -o <nameExacutable.o>
 * 
 * The intention of this program is to show the use of join for avoiding problems of main thread ending before the rest of the threads in a process
 */
void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
    std::cout << "Finished work in thread\n";
}

int main()
{
    // create thread
    std::thread thread_1(threadFunction);

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    // wait for thread to finish
    thread_1.join();

    return 0;
}