// https://www.hackerrank.com/challenges/the-power-sum
#if 1
#include <cmath>
#include <iostream>

template<typename T>
T count(T start, T degree, T sum, T target_sum)
{
    if (sum >= target_sum) {
        return sum == target_sum;
    }

    T quantity = 0;
    for(T i = start; sum + pow(i, degree) <= target_sum; ++i) {
        quantity += count(i + 1, degree, sum + static_cast<T>(pow(i, degree)), target_sum);
    }

    return quantity;
}

int main()
{
    long long x;
    std::cin >> x;
    long long n;
    std::cin >> n;

    std::cout << count<long long>(1, n, 0, x) << std::endl;

    return 0;
}

#else // slower solution
#include <cmath>
#include <iostream>
#include <functional>

template<typename T>
std::function<T(T, T)> calculate(T degree, T goal_sum)
{
    std::function<T(T, T)> count;
    count = [degree, goal_sum, &count] (T start, T sum) {
        if (sum >= goal_sum) {
            return static_cast<T>(sum == goal_sum);
        }

        T quantity = 0;
        for(T i = start; sum + pow(i, degree) <= goal_sum; ++i) {
            quantity += count(i + 1, sum + static_cast<T>(pow(i, degree)));
        }

        return quantity;
    };

    return count;
}

int main()
{
    long long x;
    std::cin >> x;
    long long n;
    std::cin >> n;

    auto count = calculate<long long>(n, x);
    std::cout << count(1, 0) << std::endl;

    return 0;
}
#endif
