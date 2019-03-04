// https://www.hackerrank.com/challenges/sherlock-and-array
#include <vector>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

static bool does_middle_exist(const std::vector<int>& data)
{
    long long left = 0, right = 0;

    for(int i = 0, j = data.size() - 1; i != j;) {
        (left <= right) ? left += data[i++] : right += data[j--];
    }

    return left == right;
}

int main()
{
    int t;
    std::cin >> t;

    for(int n = 0; t-- > 0 && std::cin >> n;) {
        std::vector<int> a;
        for(int i = 0, number; i < n && std::cin >> number; ++i, a.push_back(number));

        std::cout << (does_middle_exist(a) ? "YES" : "NO") << std::endl;
    }

    return 0;
}

#pragma GCC diagnostic pop
