// https://www.hackerrank.com/challenges/divisible-sum-pairs
#include <vector>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a;
    for (int number; n-- > 0 && std::cin >> number; a.push_back(number));

    int count = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            count += ((a[i] + a[j]) % k == 0);
        }
    }

    std::cout << count << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
