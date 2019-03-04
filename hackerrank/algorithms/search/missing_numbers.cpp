// https://www.hackerrank.com/challenges/missing-numbers
#include <vector>
#include <iostream>

#define X_MAX 10000
#define SUB_SIZE 101

int main()
{
    int number;
    int min = X_MAX + 1;

    int n;
    std::cin >> n;
    std::vector<int> a_input;
    while(n-- != 0 && std::cin >> number) {
        min = (number < min) ? number : min;
        a_input.push_back(number);
    }

    // suppose, that first array does not lose the min value
    // otherwise there is an error
    int substraction_array[SUB_SIZE] {};
    for(const auto& num : a_input) {
        substraction_array[num - min]++;
    }

    int m;
    std::cin >> m;
    std::vector<int> b_input;
    while(m-- != 0 && std::cin >> number) {
        substraction_array[number - min]--;
    }

    for(int i = 0; i < SUB_SIZE; ++i) {
        if (substraction_array[i] != 0) {
            std::cout << (i + min) << " ";
        }
    }

    return 0;
}
