// https://www.hackerrank.com/challenges/countingsort4/problem
#include <array>
#include <vector>
#include <iostream>

#define MAX_NUMBER_VALUE 100

int main()
{
    int n;
    std::cin >> n;

    std::array<std::vector<std::string>, MAX_NUMBER_VALUE> data{};
    for(int i = 0; i < n; ++i) {
        int number;
        std::string str;
        std::cin >> number >> str;
        data[number].push_back((i < (n / 2) ? "-" : str));
    }

    for(const auto& v : data) {
        for(const auto& item : v) {
            std::cout << item << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
