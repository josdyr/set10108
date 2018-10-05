#include <iostream>

int main()
{
    int a = 5;
    int b = 10;

    int& ref = a;
    ref = b;

    std::cout << a << ", " << &a << "\n";
    std::cout << b << ", " << &b << "\n";
    std::cout << ref << ", " << &ref << "\n";
}
