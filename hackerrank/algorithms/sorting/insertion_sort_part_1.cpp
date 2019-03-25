// https://www.hackerrank.com/challenges/insertionsort1
#include <vector>
#include <iostream>

template<typename T>
void print_collection(const std::vector<T>& data)
{
    for (const auto& item : data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void insertion_sort(std::vector<T>& input, T value)
{
    for (auto it = input.rbegin(); it != input.rend() - 1; ++it) {
        *it = (*(it + 1) <= value) ? value : *(it + 1);
        print_collection<T>(input);
        if (*(it + 1) <= value) {
            return;
        }
    }
    // that case for first item if we are here
    input[0] = value;
    print_collection<T>(input);
}

int main()
{
    int size;
    std::cin >> size;

    std::vector<int> data;
    for (int i = 0; i < size; ++i) {
        int number;
        std::cin >> number;
        data.push_back(number);
    }

    insertion_sort(data, data.back());

    return 0;
}
