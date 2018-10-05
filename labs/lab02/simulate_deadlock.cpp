#include <thread>
#include <iostream>
#include <memory>
#include <mutex>

using namespace std ;

/*
This is the function called by the thread
*/

mutex mut;

void inc_me(shared_ptr<int> x)
{
    for (int i = 0; i < 100; ++i)
    {
        mut.lock();
        *x = *x + 1;
        std::cout << *x << "\n";
        // mut.unlock();
    }
}

int main(int argc, char **argv)
{
    auto x = make_shared<int>(0);
    // Create a new thread
    thread t1(inc_me, x);
    thread t2(inc_me, x);
    // Wait for thread to finish (join it)
    t1.join();
    t2.join();
    // Return 0 (OK)
    return 0;
}
