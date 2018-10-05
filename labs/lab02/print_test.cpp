#include <thread>
#include <memory>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "thread::hardware_concurrency(): " << thread::hardware_concurrency() << "\n";

    return 0;
}
