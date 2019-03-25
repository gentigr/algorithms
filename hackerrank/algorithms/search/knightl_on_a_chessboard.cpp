// https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
#include <set>
#include <vector>
#include <utility>
#include <iostream>

static void initialize_field(int** field, int n)
{
    for (int i = 0; i < 3 * n; ++i) {
        for (int j = 0; j < 3 * n; ++j) {
            field[i][j] = 1;
        }
    }
    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            field[i][j] = 0;
        }
    }
}

static std::set<std::pair<int, int>> get_next_positions(
                                          int** field,
                                          std::set<std::pair<int, int>>& positions,
                                          int x,
                                          int y)
{
    std::vector<std::pair<int, int>> changes{};
    changes.push_back(std::make_pair(x, y));
    changes.push_back(std::make_pair(x, -y));
    changes.push_back(std::make_pair(-x, y));
    changes.push_back(std::make_pair(-x, -y));
    changes.push_back(std::make_pair(y, x));
    changes.push_back(std::make_pair(y, -x));
    changes.push_back(std::make_pair(-y, x));
    changes.push_back(std::make_pair(-y, -x));

    std::set<std::pair<int, int>> new_positions{};
    for (auto& position : positions) {
        for (auto& change : changes) {
            int new_x = position.first + change.first;
            int new_y = position.second + change.second;
            if (field[new_x][new_y] == 0) {
                new_positions.insert(std::make_pair(new_x, new_y));
                field[new_x][new_y] = 1;
            }
        }
    }

    return new_positions;
}

static int find_the_shortest_path(int** field, int n, int x, int y)
{
    std::set<std::pair<int, int>> positions{};
    positions.insert(std::make_pair(n, n));
    field[n][n] = 1;

    int steps = 0;
    do {
        positions = get_next_positions(field, positions, x, y);
        ++steps;
    } while (!positions.empty()
             && positions.count(std::make_pair(2 * n - 1, 2 * n - 1)) == 0);

    return positions.empty() ? -1 : steps;
}

static int** allocate_2dim(int size)
{
    int** mem = new int* [size];
    for (int i = 0; i < size; ++i) {
        mem[i] = new int[size];
    }
    return mem;
}

static void deallocate_2dim(int** mem, int size)
{
    for (int i = 0; i < size; ++i) {
        delete[] mem[i];
    }
    delete[] mem;
}

int main()
{
    int n;
    std::cin >> n;

    int** answer = allocate_2dim(n);
    int** field = allocate_2dim(3 * n);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            initialize_field(field, n);
            answer[i][j] = find_the_shortest_path(field, n, i + 1, j + 1);
            answer[j][i] = answer[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            std::cout << answer[i][j] << " ";
        }
        std::cout << std::endl;
    }

    deallocate_2dim(answer, n);
    deallocate_2dim(field, 3 * n);

    return 0;
}
