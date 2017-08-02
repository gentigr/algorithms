// https://www.hackerrank.com/challenges/insertionsort2
#include <vector>
#include <iostream>

template<typename T>
void print_collection(const std::vector<T>& data)
{
    for(const auto& item : data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void insertion_sort(std::vector<T>& input)
{
    for(auto outer = input.begin() + 1; outer < input.end(); ++outer) {
        auto value = *outer;
        for(auto inner = outer; inner >= input.begin() && *inner >= value; --inner) {
            *inner = (*(inner - 1) <= value) ? value : *(inner - 1);
        }
        print_collection<T>(input);
    }
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

    insertion_sort(data);

    return 0;
}
