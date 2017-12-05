// https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
#include <array>
#include <iostream>

#define MAX_N 100001

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::array<int, MAX_N> houses{};
    for(int num; n-- > 0 && std::cin >> num; houses[num] = 1);

    int count = 0;
    for(int i = 0; i < houses.size(); ++i) {
        if (houses[i] == 1) {
            ++count;
            for(i = i + k; i < houses.size() && houses[i] == 0; --i);
            for(i = i + k; i < houses.size() && houses[i] == 0; --i);
        }
    }

    std::cout << count << std::endl;

    return 0;
}
