// https://www.hackerrank.com/challenges/the-hurdle-race
#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    int max = 0;
    for (int number; n-- > 0 && std::cin >> number;) {
        max = number > max ? number : max;
    }

    std::cout << (k > max ? 0 : max - k) << std::endl;

    return 0;
}
