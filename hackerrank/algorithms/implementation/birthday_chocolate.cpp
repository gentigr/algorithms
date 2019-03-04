// https://www.hackerrank.com/challenges/the-birthday-bar/problem
#include <vector>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

int main()
{
    int count;
    std::cin >> count;

    std::vector<int> squares;
    for (int n; count-- > 0 && std::cin >> n; squares.push_back(n));

    int d, m;
    std::cin >> d >> m;

    int sum = 0, breaks_count = 0;
    for (int i = 0; i < m && i < squares.size(); sum += squares[i], ++i);
    breaks_count += (sum == d);
    for (int i = 0, j = m; j < squares.size(); ++i, ++j) {
        sum = sum - squares[i] + squares[j];
        breaks_count += (sum == d);
    }

    std::cout << breaks_count << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
