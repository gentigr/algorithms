// http://codeforces.com/problemset/problem/158/B
#include <array>
#include <cmath>
#include <iostream>

#define MAX_CAPACITY 4

int main(int argc, char* argv[])
{
    std::array<long long int, MAX_CAPACITY> groups{};
    int n;
    int s;
    for(std::cin >> n; n-- > 0; std::cin >> s, groups[s - 1]++);

    long long int count = groups[3] + groups[2] + groups[1] / 2;
    groups[0] -= groups[2];

    if ((groups[1] % 2) > 0) {
        groups[0] -= 2;
        count++;
    }

    if (groups[0] > 0) {
        count += ceil(static_cast<double>(groups[0]) / MAX_CAPACITY);
    }

    std::cout << count << std::endl;

    return 0;
}
