// https://www.hackerrank.com/challenges/big-sorting
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::map<int, std::vector<std::string>> data;
    while(n-- != 0) {
        std::string number;
        std::cin >> number;
        data[number.size()].push_back(number);
    }

    for(auto& kv : data) {
        std::sort(kv.second.begin(), kv.second.end());
        for(const auto& num : kv.second) {
            std::cout << num << std::endl;
        }
    }

    return 0;
}
