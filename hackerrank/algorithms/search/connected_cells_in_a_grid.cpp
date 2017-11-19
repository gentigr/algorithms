// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
#include <vector>
#include <utility>
#include <iostream>

// this function clears cells which were found during investigation
std::vector<std::pair<int, int>> investigate_region(
                                  int** matrix, int row, int column)
{
    std::vector<std::pair<int, int>> to_visit = {
        std::make_pair(row - 1, column - 1),
        std::make_pair(row - 1, column),
        std::make_pair(row - 1, column + 1),
        std::make_pair(row, column - 1),
        std::make_pair(row, column + 1),
        std::make_pair(row + 1, column - 1),
        std::make_pair(row + 1, column),
        std::make_pair(row + 1, column + 1)
    };

    std::vector<std::pair<int, int>> filled_cells;
    for (auto c : to_visit) {
        if (matrix[c.first][c.second] == 1) {
            filled_cells.push_back(std::make_pair(c.first, c.second));
            matrix[c.first][c.second] = 0;
        }
    }

    return filled_cells;
}

// this function clears filled cells during search
int get_current_region_size(int** matrix, int row, int column)
{
    int region_size = 0;

    matrix[row][column] = 0;
    std::vector<std::pair<int, int>> v = { std::make_pair(row, column) };
    do {
        region_size += v.size();
        std::vector<std::pair<int, int>> new_v{};
        for (auto point : v) {
            auto coords = investigate_region(matrix,
                                             point.first,
                                             point.second);
            new_v.insert(std::end(new_v),
                         std::begin(coords),
                         std::end(coords));
        }
        v = new_v;
    } while(!v.empty());

    return region_size;
}

int get_max_region_size(int** matrix, int rows, int columns)
{
    int max_region_size = -1;
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < columns - 1; ++j) {
            int region_size = 0;
            if (matrix[i][j] == 1) {
                region_size = get_current_region_size(matrix, i, j);
                if (region_size > max_region_size) {
                    max_region_size = region_size;
                }
            }
        }
    }

    return max_region_size;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int** matrix = new int*[n + 2];
    for (int i = 0; i < n + 2; ++i) {
        matrix[i] = new int[m + 2];
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1, number; j < m + 1; ++j) {
            std::cin >> number;
            matrix[i][j] = number;
        }
    }

    std::cout << get_max_region_size(matrix, n + 2, m + 2) << std::endl;

    for (int i = 0; i < n + 2; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
