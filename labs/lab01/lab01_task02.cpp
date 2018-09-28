#include <thread>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void my_multiply(std::vector<int> &my_vector, std::vector<std::vector<int>> &my_matrix)
{
    std::vector<int> result_vector(2);
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 2; ++col)
        {
            std::cout << "v:" << my_vector[col] << " * " << "m:" << my_matrix[row][col] << "\n";
            result_vector[col] = my_vector[col] * my_matrix[row][col];
        }
    }

    //print result
    std::cout << result_vector[0] << ", " << result_vector[1] << "\n";
}

int main(int argc, char **argv)
{
    int vec_size = 2;
    int rows_count = 2;
    int cols_count = 2;

    std::vector<int> my_vector(vec_size);
    std::vector<std::vector<int>> my_matrix(rows_count, std::vector<int>(cols_count));

    // random_device r;
    // default_random_engine e(r());

    //populate vector and matrix with random numbers
    int val = 1;
    for (int row = 0; row < vec_size; ++row)
    {
        // my_vector[row] = e();
        std::cout << "v: " << val << "\n";
        my_vector[row] = val++;
        for (int col = 0; col < cols_count; ++col)
        {
            // my_matrix[row][col] = e();
            std::cout << "m: " << val << "\n";
            my_matrix[row][col] = val++;
        }
    }

    for (int row = 0; row < vec_size; ++row)
    {
        for (int col = 0; col < cols_count; ++col)
        {
            std::cout << "my_matrix[row][col]: " << my_matrix[row][col] << "\n";
        }
    }

    for (int i = 0; i < vec_size; ++i)
    {
        std::cout << "my_vector[i]: " << my_vector[i] << "\n";
    }

    my_multiply(my_vector, my_matrix);

    std::cout << "my_vector: ";
    for (int col = 0; col < 2; ++col)
    {
        std::cout << my_vector[col] << ", ";
    }

    return 0;
}
