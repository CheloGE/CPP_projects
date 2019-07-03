#include <iostream>

/***
 * Please run this program using C++11 
 * To compile with MinGW64 use: gcc <file.cpp> -lstdc++ -o <nameExacutable.o>
 */

class MyClass
{
  private:
    float val;

  public:
    MyClass(float b)
    {
        val = b;
    }
    float operator()(float a) //This means that whenever the operation "( )" is used in any MyClass object it will return a multiplication of the objects initial value.
    {
        return val * a;
    }
};

int main()
{
    MyClass A(2);
    std::cout << "Multiplication of 2 by 3 " << A(3) << std::endl;
    MyClass B(3);
    std::cout << "Multiplication of 3 by 10 " << B(10) << std::endl;
    return 0;
}