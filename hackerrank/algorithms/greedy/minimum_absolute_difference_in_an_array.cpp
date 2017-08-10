// https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_POSSIBLE_DIFFERENCE 2000000000

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> a;
    for(int number; n-- != 0 && std::cin >> number;) {
        a.push_back(number);
    }

    std::sort(a.begin(), a.end());

    int min_difference = MAX_POSSIBLE_DIFFERENCE + 1;
    for(int i = 1; i < a.size(); ++i) {
        if (abs(a[i - 1] - a[i]) < min_difference) {
            min_difference = abs(a[i - 1] - a[i]);
        }
    }

    std::cout << min_difference << std::endl;

    return 0;
}
