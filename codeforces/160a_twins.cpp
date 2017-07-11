// http://codeforces.com/problemset/problem/160/A
#include <array>
#include <iostream>

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    std::array<int, 101> counts{};
    while(n-- > 0) {
        int a;
        std::cin >> a;
        ++counts[a];
    }

    long long int sum = 0;
    for(int i = 0; i < counts.size(); ++i) {
        sum += counts[i] * i;
    }

    long long int vicious_twin_sum = 0;
    int vicious_twin_coins_count = 0;
    for(int i = counts.size() - 1; i > 0 && vicious_twin_sum <= sum; --i) {
        for(int j = counts[i]; j > 0 && vicious_twin_sum <= sum; --j) {
            sum -= i;
            vicious_twin_sum += i;
            ++vicious_twin_coins_count;
        }
    }

    std::cout << vicious_twin_coins_count << std::endl;
    return 0;
}
