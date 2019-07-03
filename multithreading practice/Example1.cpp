#include <iostream>
#include <thread>

/***
 * Please run this program using C++11 
 * To compile with MinGW64 use: <gcc file.cpp> -lstdc++ -o <nameExacutable.o>
 */
int main()
{

    // This line prints out the thread id for the main thread.
    std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;

    // The following line prints out the number of CPU cores to use for concurrency
    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "This machine supports concurrency with " << nCores << " cores available" << std::endl;

    return 0;
}