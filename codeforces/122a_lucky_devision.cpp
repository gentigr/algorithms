// http://codeforces.com/problemset/problem/122/A
#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    std::vector<int> lucky_numbers;
    for (int i = 4; i <= n; i++) {
        std::string number = std::to_string(i);
        auto it = number.cbegin();
        for (; it != number.cend() && (*it == '4' || *it == '7'); ++it);
        if (it == number.cend()) {
            lucky_numbers.push_back(i);
        }
    }

    auto it = std::find_if(lucky_numbers.cbegin(), lucky_numbers.cend(), [&n](int c) {
        return n % c == 0;
    });
    std::cout << (it == lucky_numbers.cend() ? "NO" : "YES") << std::endl;

    return 0;
}
