#include <iostream>
#include <vector>

using irow = std::vector<int>;
using imatrix = std::vector<irow>;

void fill_matrix(imatrix& matrix, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        matrix.push_back(std::vector<int>());

        for (int j = 0; j < col; j++)
        {
            int input;
            std::cin >> input;
            matrix[i].push_back(j);
            matrix.at(i).at(j) = input;
        }
    }
}

void matrix_product(const imatrix matrix1, const int row1, const imatrix matrix2, const int row2, const int col2, imatrix& result_matrix)
{
    for (int row = 0; row < row1; row++)
    {
        result_matrix.push_back(std::vector<int>());

        for (int col = 0; col < col2; col++)
        {
            result_matrix[row].push_back(col);
            int temp = 0;

            for (int i = 0; i < row2; i++)
            {
                temp += matrix1.at(row).at(i) * matrix2.at(i).at(col);
            }
            result_matrix.at(row).at(col) = temp;
        }
    }
}

void read_vector(const imatrix matrix, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << matrix.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int row1;
    int col1;
    imatrix matrix1;
    int row2;
    int col2;
    imatrix matrix2;
    imatrix result_matrix;

    std::cout << "enter first matrix" << std::endl;
    std::cout << "enter number of rows:" << std::endl;
    std::cin >> row1;
    std::cout << "enter number of columns:" << std::endl;
    std::cin >> col1;
    fill_matrix(matrix1, row1, col1);

    std::cout << "enter second matrix" << std::endl;
    std::cout << "enter number of rows:" << std::endl;
    std::cin >> row2;
    std::cout << "enter number of columns:" << std::endl;
    std::cin >> col2;
    fill_matrix(matrix2, row2, col2);

    if (col1 != row2)
    {
        std::cout << "false input!";
    }

    else
    {
        matrix_product(matrix1, row1, matrix2, row2, col2, result_matrix);

        std::cout << "result matrix:" << std::endl;

        read_vector(result_matrix, row1, col2);
    }

    return 0;
}