// https://www.hackerrank.com/challenges/recursive-digit-sum
#include <iostream>
#include <algorithm>

static long long determine_super_digit(std::string number)
{
    long long sum = 0;
    std::for_each(number.cbegin(), number.cend(), [&sum](const char c) {
        sum += (c - 48);
    });
    return sum > 9 ? determine_super_digit(std::to_string(sum)) : sum;
}

int main()
{
    std::string n;
    std::cin >> n;
    int k;
    std::cin >> k;

    long long result = determine_super_digit(n);
    std::cout << determine_super_digit(std::to_string(result * k)) << std::endl;

    return 0;
}
