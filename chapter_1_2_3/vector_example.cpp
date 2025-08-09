#include <iostream>
#include <vector>

#define N 10
#define M 20

int main()
{
    // 1. Use std::vector for dynamic arrays (no manual pointer arithmetic needed)
    std::vector<char> letters(N);
    std::vector<int> numbers(N);
    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));

    // 2. Initialize letters and numbers using range-based for loop and indexing
    for (int i = 0; i < N; ++i)
    {
        letters[i] = 'a' + i; // Assign letters 'a' to 'j'
        numbers[i] = i * 3;   // Assign multiples of 3
    }

    // 3. Print the letters array
    std::cout << "letters: ";
    for (char c : letters)
    {
        std::cout << c << ' ';
    }
    std::cout << std::endl;

    // 4. Print the numbers array
    std::cout << "numbers: ";
    for (int n : numbers)
    {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    // 5. Fill and print a 2D matrix
    int value = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            matrix[i][j] = value++;
        }
    }
    std::cout << "matrix[0][0..4]: ";
    for (int j = 0; j < 5; ++j)
    {
        std::cout << matrix[0][j] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
