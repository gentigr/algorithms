// https://www.hackerrank.com/challenges/sum-vs-xor
#include <iostream>

int main()
{
    unsigned long long n;
    std::cin >> n;

    unsigned long long count = 0;
    for (; n != 0; count += (n % 2 == 0), n >>= 1);

    std::cout << (1L << count) << std::endl;

    return 0;
}
