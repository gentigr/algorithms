// https://www.hackerrank.com/challenges/electronics-shop/forum
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int s, n, m;
    std::cin >> s >> n >> m;

    std::vector<int> keyboards{};
    for(int cost; n-- > 0 && std::cin >> cost; keyboards.push_back(cost));
    std::sort(keyboards.rbegin(), keyboards.rend());

    std::vector<int> drives{};
    for(int cost; m-- > 0 && std::cin >> cost; drives.push_back(cost));
    std::sort(drives.begin(), drives.end());

    int max_cost = -1;
    for(int i = 0, j = 0; i < keyboards.size(); ++i) {
        for(; j < drives.size() && drives[j] + keyboards[i] <= s; ++j) {
            max_cost = (drives[j] + keyboards[i] > max_cost ? drives[j] + keyboards[i] : max_cost);
        }
    }

    std::cout << max_cost << std::endl;

    return 0;
}
