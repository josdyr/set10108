#include <iostream>

int main()
{
    int a = 5;
    int* ptr = &a;
    *ptr = 10;

    std::cout << a << "\n";
}
