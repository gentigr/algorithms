// https://www.hackerrank.com/challenges/lonely-integer
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int result = 0;
    for (int number; n-- != 0 && std::cin >> number; result ^= number);

    std::cout << result << std::endl;

    return 0;
}
