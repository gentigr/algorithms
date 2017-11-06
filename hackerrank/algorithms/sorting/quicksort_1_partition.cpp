// https://www.hackerrank.com/challenges/quicksort1/problem
#include <vector>
#include <iostream>

int main()
{
    int count;
    std::cin >> count;

    int pivot;
    std::cin >> pivot;

    std::vector<int> left{}, right{};
    for(int number; count-- > 1 && std::cin >> number;) {
        ((number > pivot) ? right : left).push_back(number);
    }

    left.push_back(pivot);
    left.insert(std::end(left), std::begin(right), std::end(right));
    for(int t : left) {
        std::cout << t << " ";
    }
    std::cout << std::endl;

    return 0;
}
