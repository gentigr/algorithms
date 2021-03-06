// https://www.hackerrank.com/challenges/mars-exploration
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

int main()
{
    const std::string sos { "SOS" };

    std::string str;
    std::cin >> str;

    int count_of_mistakes = 0;
    for (int i = 0; i < str.size(); ++i) {
        count_of_mistakes += (str[i] != sos[i % 3]);
    }

    std::cout << count_of_mistakes << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
