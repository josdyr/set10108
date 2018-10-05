#include <iostream>
#include <memory>
#include <vector>
#include <thread>

using namespace std;
using namespace chrono;

void increment(shared_ptr<int> value)
{
    // Loop 1 million times, incrementing value
    for (unsigned int i = 0; i < 100000; ++i)
        // Increment value
        *value = *value + 1;
}

int main(int argc, char **argv)
{
    // Create a shared int value
    auto value = make_shared<int>(0);

    // Create number of threads hardware natively supports
    auto num_threads = thread::hardware_concurrency();
    std::cout << "nr of threads: " << thread::hardware_concurrency() << "\n";
    // std::cout << "nr of threads: ";
    // std::cin >> num_threads;

    vector<thread> threads;

    auto start = system_clock::now();
    for (unsigned int i = 0; i < num_threads; ++i)
        threads.push_back(thread(increment, value));

    // Join the threads
    for (auto &t : threads)
        t.join();
    auto end = system_clock::now();
    auto total_time = end - start;

    // total time est: ~2.0 micro seconds...
    std::cout << "total_time: " << total_time.count() / 1000.0f << " ms\n";

    // Display the value
    cout << "value = " << *value << endl;
}
