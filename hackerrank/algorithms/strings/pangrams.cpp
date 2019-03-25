// https://www.hackerrank.com/challenges/pangrams/problem
#include <array>
#include <iostream>
#include <algorithm>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

static bool is_pangram(const std::string& sentence)
{
    const int ALPHABET_LENGTH = 25;
    std::array<int, ALPHABET_LENGTH> letters{};

    // there is should be check for ' ' inside this lambda
    std::for_each(sentence.cbegin(), sentence.cend(), [&letters](char c) {
        ++letters[c - ((c > 'Z') ? 'a' : 'A')];
    });

    return std::none_of(letters.cbegin(), letters.cend(), [](int i) {
        return i == 0;
    });
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::cout << (is_pangram(s) ? "" : "not ") << "pangram" << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
