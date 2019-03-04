// https://www.hackerrank.com/challenges/between-two-sets
#include <vector>
#include <iostream>
#include <algorithm>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a;
    for(int number; n-- > 0 && std::cin >> number; a.push_back(number));
    std::sort(a.begin(), a.end());

    std::vector<int> b;
    for(int number; m-- > 0 && std::cin >> number; b.push_back(number));
    std::sort(b.begin(), b.end());

    int count = 0;
    for(int x = a.back(); x <= b.front(); ++x) {
        bool emerg = false;

        // 1. All elements in A are factors of x.
        for(int j = 0; j < a.size() && !emerg; ++j) {
            emerg = (x % a[j] != 0);
        }
        if (emerg) {
            continue;
        }

        // 2. x is a factor of all elements in B.
        for(int j = 0; j < b.size() && !emerg; ++j) {
            emerg = (b[j] % x != 0);
        }
        if (emerg) {
            continue;
        }

        ++count;
    }

    std::cout << count << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
