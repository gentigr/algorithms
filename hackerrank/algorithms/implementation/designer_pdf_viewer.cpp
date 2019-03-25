// https://www.hackerrank.com/challenges/designer-pdf-viewer
#include <array>
#include <iostream>

#define LETTERS_COUNT 26

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

int main()
{
    std::array<int, LETTERS_COUNT> alphabet{};
    for (int i = 0, height; i < LETTERS_COUNT &&
            std::cin >> height; alphabet[i] = height, ++i);

    std::string word;
    std::cin >> word;

    int max = 0;
    for (char c : word) {
        max = (alphabet[c - 'a'] > max) ? alphabet[c - 'a'] : max;
    }

    std::cout << (word.size() * max) << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
