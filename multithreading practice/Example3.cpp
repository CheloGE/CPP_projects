#include <iostream>
#include <thread>

/***
 * Please run this program using C++11 
 * To compile with MinGW64 use: <gcc file.cpp> -lstdc++ -o <nameExacutable.o>
 * 
 * The intention of this program is to show that the scheduler assign task randomly, thus concurrency is non deterministic.
 * You can see this by running this program several times, where the output will most likely different
 */
void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 1 in thread\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in thread\n";
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 1 in main\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in main\n";

    // wait for thread to finish
    t.join();

    return 0;
}