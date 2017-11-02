// https://www.hackerrank.com/challenges/separate-the-numbers/problem
#include <iostream>

std::string get_next_value(const std::string& number)
{
    long long int value = std::stoll(number);
    return std::to_string(value + 1);
}

long long int beautiful(const std::string& str)
{
    for(int length = 1; length < str.size() / 2 + 1; ++length) {
        std::string current_number = str.substr(0, length);
        bool success = true;
        for(int current_position = length;
                current_position < str.size() && success;) {

            std::string next_number = get_next_value(current_number);
            if (next_number == str.substr(current_position, next_number.size())) {
                current_number = next_number;
                current_position += next_number.size();
            } else {
                success = false;
            }
        }
        if (success) {
            return std::stoll(str.substr(0, length));
        }
    }

    return -1;
}

int main()
{
    int n;
    std::cin >> n;

    for (std::string str; n-- > 0 && std::cin >> str; ) {
        long long int smallest = beautiful(str);
        if (smallest == -1) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES " << smallest << std::endl;
        }
    }

    return 0;
}
