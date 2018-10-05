#include <iostream>

void increment(int& value)
{
    value++;
    std::cout << "value" << ": " << value << "\n";
    std::cout << "&value" << ": " << &value << "\n";
}

int main()
{
    int a = 5;
    increment(a);

    std::cout << a << ", " << &a << "\n";
}
