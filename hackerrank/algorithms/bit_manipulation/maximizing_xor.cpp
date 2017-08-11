// https://www.hackerrank.com/challenges/maximizing-xor
#include <iostream>

int main()
{
    int l;
    std::cin >> l;
    int r;
    std::cin >> r;

    int max = -1;
    for(int i = l; i < r; ++i) {
        for(int j = i + 1; j <= r; ++j) {
            max = ((i ^ j) > max) ? i ^ j : max;
        }
    }
    std::cout << max << std::endl;

    return 0;
}
