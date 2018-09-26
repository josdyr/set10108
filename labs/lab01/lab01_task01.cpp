#include <thread>
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <chrono>
#include <tuple>

using namespace std ;
using namespace std::chrono ;

std::tuple<int, int> find_max_min(vector<int> random_numbers)
{
    int max = 0; //lowest nr
    int min = std::numeric_limits<int>::max(); //inf. high nr

    for (int r : random_numbers)
    {
        // std::cout << "random nr: " << r << "\n";
        if (max < r)
        {
            max = r;
            // std::cout << "max = " << r << "\n";
        }
        if (min > r)
        {
            min = r;
            // std::cout << "min: " << r << "\n";
        }
    }
    std::cout << "(" << min << ", " << max << ")" << "\n";

    // std::cout << {min, max} << "\n";
    return {min, max};
}

int main(int argc, char **argv)
{
    //allocate vector
    vector<int> random_numbers;

    random_device r;
    default_random_engine e(r());

    auto start = system_clock::now();

    //generate random nr and append to vector
    for (int i = 0; i < 10000000; ++i)
    {
        random_numbers.push_back(e());
    }

    find_max_min(random_numbers);

    auto end = system_clock::now();
    auto total = end - start;
    std::cout << "total: " << total.count() << "\n";

    // std::cout << my_tuple << "\n";
    return 0;
}
