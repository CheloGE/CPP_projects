#include <iostream>
#include <thread>

/***
 * Please run this program using C++11 
 * To compile with MinGW64 use: <gcc file.cpp> -lstdc++ -o <nameExacutable.o>
 * 
 * The intention of this program is to show that detach is a flag to tell the compiler to not call the destructor for the thread 
 * so that the error from not having a join function is avoid
 * However this has its own risks and it's not recommended
 */
void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread\n";
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    // detach thread and continue with main
    t.detach();

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    return 0;
}