// https://www.hackerrank.com/challenges/marcs-cakewalk
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> calories;
    for(int c; n-- != 0 && std::cin >> c; calories.push_back(c));
    std::sort(calories.rbegin(), calories.rend());

    long long miles_count = 0;
    for(int i = 0; i < calories.size(); ++i) {
        miles_count += calories[i] * pow(2, i);
    }

    std::cout << miles_count << std::endl;

    return 0;
}
