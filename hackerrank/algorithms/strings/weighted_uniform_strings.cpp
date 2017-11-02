// https://www.hackerrank.com/challenges/weighted-uniform-string/problem
#include <set>
#include <iostream>

int main()
{
    std::string line;
    std::cin >> line;

    std::set<int> sums{};
    for (int i = 0, prev = 0, times = 0; i < line.size(); ++i) {
        times = ((line[i] != line[prev]) ? 1 : times + 1);
        prev = ((line[i] != line[prev]) ? i : prev);
        sums.insert((line[i] - 'a' + 1) * times);
    }

    int n;
    std::cin >> n;
    for (int number;
            n-- > 0 && std::cin >> number;
            std::cout << ((sums.count(number) == 1) ? "Yes" : "No") << std::endl);

    return 0;
}
