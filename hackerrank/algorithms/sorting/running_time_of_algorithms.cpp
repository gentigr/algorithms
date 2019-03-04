// https://www.hackerrank.com/challenges/runningtime/problem
#include <vector>
#include <iostream>

template<typename T>
int get_number_of_shifts_insertion_sort(std::vector<T>& input)
{
    int number_of_shifts = 0;
    for(auto outer = input.begin() + 1; outer < input.end(); ++outer) {
        auto value = *outer;
        for(auto inner = outer; inner >= input.begin() && *inner >= value; --inner) {
            *inner = (*(inner - 1) <= value) ? value : *(inner - 1);
            number_of_shifts += (*(inner - 1) > value);
        }
    }

    return number_of_shifts;
}

int main()
{
    int size;
    std::cin >> size;

    std::vector<int> data;
    for(int i = 0; i < size; ++i) {
        int number;
        std::cin >> number;
        data.push_back(number);
    }

    std::cout << get_number_of_shifts_insertion_sort(data) << std::endl;

    return 0;
}
