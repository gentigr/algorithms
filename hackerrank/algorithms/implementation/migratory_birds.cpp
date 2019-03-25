// https://www.hackerrank.com/challenges/migratory-birds
#include <iostream>
#include <unordered_map>

int main()
{
    int n;
    std::cin >> n;

    std::unordered_map<int, int> count_of_types{};
    for (int number; n-- > 0 && std::cin >> number; count_of_types[number]++);

    int key_with_max_value = 1;
    for (const auto& kv : count_of_types) {
        if (kv.second > count_of_types[key_with_max_value]) {
            key_with_max_value = kv.first;
        }
    }

    std::cout << key_with_max_value << std::endl;

    return 0;
}
