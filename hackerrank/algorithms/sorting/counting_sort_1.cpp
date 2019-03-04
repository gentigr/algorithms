// https://www.hackerrank.com/challenges/countingsort1/problem
#include <array>
#include <iostream>

#define MAX_ARRAY_SIZE 100

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

int main()
{
    int n;
    std::cin >> n;

    std::array<int, MAX_ARRAY_SIZE> counters{};
    for(int num; n-- > 0 && std::cin >> num; ++counters[num]);

    for(int num = 0; num < counters.size(); std::cout << counters[num++] << " ");
    std::cout << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
