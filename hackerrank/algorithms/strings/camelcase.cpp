// https://www.hackerrank.com/challenges/camelcase
#include <iostream>
#include <algorithm>

int main()
{
    std::string line;
    std::cin >> line;

    int count = 0;
    auto solver = [&count](char c) {
        count += (c > 64 && c < 91);
    };
    std::for_each(line.begin(), line.end(), solver);

    std::cout << (count + 1) << std::endl;

    return 0;
}
