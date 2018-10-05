#include <thread>
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <chrono>
#include <tuple>
#include <future>
#include <algorithm>

using namespace std ;
using namespace std::chrono ;

int VECTOR_SIZE = 100000000;

std::tuple<int, int> find_min_max(vector<int> &random_numbers, int random_numbers_split_count, int thread_index)
{

    int start = random_numbers_split_count * thread_index;
    int end = random_numbers_split_count * thread_index + random_numbers_split_count;

    // std::cout <<  << "\n";

    // std::cout << random_numbers_split_count << ", " << thread_index << "\n";
    // std::cout << "random_numbers.size(): " << random_numbers.size() << "\n";

    int max = 0; //lowest nr
    int min = std::numeric_limits<int>::max(); //inf. high nr

    for (int i = start; i < end; ++i)
    {
        if (max < random_numbers[i])
        {
            max = random_numbers[i];
        }
        if (min > random_numbers[i])
        {
            min = random_numbers[i];
        }
    }

    std::cout << "idx: " << thread_index << ", (" << max << ", " << min << ")\n";
    return std::make_tuple(min, max);
}

int main(int argc, char **argv)
{

    int max = 0; //lowest nr
    int min = std::numeric_limits<int>::max(); //inf. high nr

    vector<int> random_numbers;
    random_device r;
    default_random_engine e(r());


    // std::cout << "start: " << start << "\n";

    //generate random nr and append to vector
    for (int i = 0; i < VECTOR_SIZE; ++i)
    {
        random_numbers.push_back(e());
    }

    int thread_count = 0;
    std::cout << "thread count: ";
    std::cin >> thread_count;
    int random_numbers_split_count = floor(VECTOR_SIZE / thread_count);
    std::cout << "vector split count: " << random_numbers_split_count << "\n";

    std::vector<future<std::tuple<int, int>>> threads_vector;

    auto start = system_clock::now();
    for (int i = 0; i < thread_count; ++i)
    {
        threads_vector.push_back(async(find_min_max, ref(random_numbers), random_numbers_split_count, i));
    }

    for (auto &t : threads_vector)
    {
        auto result = t.get();
        // std::cout << "get<0>(result): " << get<0>(result) << "\n";

        if (get<0>(result) < min)
        {
            min = get<0>(result);
        }
        if (get<1>(result) > max)
        {
            max = get<1>(result);
        }
    }

    std::cout << "max: " << max << ", min: " << min << "\n";

    std::cout << "\n";
    auto end = system_clock::now();
    auto total = end - start;

    for (int i = 0; i < total.count() / 1000; i+=4)
    {
        std::cout << ".";
    }
    std::cout << "time: " << total.count() / 1000 << "ms" << " (" << thread_count << "t)" << "\n";

    return 0;
}
