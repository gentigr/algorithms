// https://www.hackerrank.com/challenges/luck-balance
#include <vector>
#include <iostream>
#include <algorithm>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> l{};
    for(int number, t; n-- > 0 && std::cin >> number >> t;) {
        // yes, we can collect here (t == 0) directly into luck_balance,
        // but it seems like we may skip it for current constraints
        l.push_back((t == 0) ? number : -number);
    }

    std::sort(l.begin(), l.end());
    for(int i = 0; i < k; ++i) {
        l[i] = abs(l[i]);
    }

    long long luck_balance = 0;
    std::for_each(l.cbegin(), l.cend(), [&luck_balance](int b) {
        luck_balance += b;
    });

    std::cout << luck_balance << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
