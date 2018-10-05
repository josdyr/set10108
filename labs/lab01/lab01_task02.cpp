#include <thread>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void my_multiply(std::vector<int> &my_vector, std::vector<std::vector<int>> &my_matrix, std::vector<int> &result_vector, int &vec_size)
{
    int row = 0;
    int col = 0;

    for (int i = 0; i < vec_size; ++i)
    {
        result_vector[i] = (my_vector[col] * my_matrix[row][col+i]) + (my_vector[col+1] * my_matrix[row+1][col+i]);
        // std::cout << my_vector[col] << " * " << my_matrix[row][col+i] << " + " << my_vector[col+1] << " * " << my_matrix[row+1][col+i] << "\n";
    }
}

int main(int argc, char **argv)
{
    int vec_size = 2;
    int rows_count = 2;
    int cols_count = 2;

    std::vector<int> my_vector(vec_size);
    std::vector<int> result_vector(vec_size);
    std::vector<std::vector<int>> my_matrix(rows_count, std::vector<int>(cols_count));

    // random_device r;
    // default_random_engine e(r());

    //populate vector and matrix with random numbers
    my_vector[0] = 1;
    my_vector[1] = 2;

    my_matrix[0][0] = 3;
    my_matrix[0][1] = 4;
    my_matrix[1][0] = 5;
    my_matrix[1][1] = 6;

    my_multiply(my_vector, my_matrix, result_vector, vec_size);

    std::cout << "my_vector: ";
    std::cout << result_vector[0] << ", " << result_vector[1];

    return 0;
}
