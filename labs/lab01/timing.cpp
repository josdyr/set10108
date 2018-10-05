#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;
using namespace std::chrono;

void work ()
{
    // Do some spinning - no actual processing but will make the CPU work
    int n = 0;
    for (int i = 0; i < 1000000; ++i)
        ++n;
}

int main(int argc, char **argv)
{
    // Create a new file
    ofstream data("data.csv", ofstream::out);
    // We’re going to gather 100 readings , so create a thread and join it 100 times
    auto start_total_time = system_clock::now();
    std::cout << typeid(start_total_time).name() << "\n";

    int j = 0;
    std::cout << "typeid(j).name(): " << typeid(j) << "\n";

    for (int i = 0; i < 100; ++i)
    {
        // Get start time
        auto start = system_clock::now();
        // Start thread
        thread t (work);
        t.join();
        // Get end time
        auto end = system_clock::now();
        // Calculate the duration
        std::chrono::duration<double> total = end - start;
        std::cout << "i: " << i << "\t time: " << total.count() * 1000 << " ms" << "\n";

        // Write to file
        data << total.count() << endl;
    }
    auto end_total_time = system_clock::now();
    std::chrono::duration<double> diff = end_total_time - start_total_time;

    std::cout << "total_time: " << diff.count() << " s\n";
    // 100 iterations complete.
    data.close();
    return 0;
}
