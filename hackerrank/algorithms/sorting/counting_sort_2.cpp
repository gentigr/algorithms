// https://www.hackerrank.com/challenges/countingsort2/problem
#include <array>
#include <iostream>

#define MAX_NUMBER_VALUE 100

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

int main()
{
    int n;
    std::cin >> n;

    std::array<int, MAX_NUMBER_VALUE> counters{};
    for(int num; n-- > 0 && std::cin >> num; ++counters[num]);

    for(int num = 0; num < counters.size(); ++num) {
        for (; counters[num]-- > 0; std::cout << num << " ");
    }
    std::cout << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
