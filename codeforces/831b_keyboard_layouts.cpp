// http://codeforces.com/problemset/problem/831/B
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ALPHABET_SIZE 26

int main(int argc, char* argv[])
{
    std::string wrong_layout;
    std::string correct_layout;
    std::string message;
    std::cin >> wrong_layout >> correct_layout >> message;

    std::unordered_map<char, char> match(ALPHABET_SIZE * 2);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        match[wrong_layout[i]] = correct_layout[i];
    }

    std::transform(wrong_layout.begin(), wrong_layout.end(), wrong_layout.begin(), ::toupper);
    std::transform(correct_layout.begin(), correct_layout.end(), correct_layout.begin(), ::toupper);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        match[wrong_layout[i]] = correct_layout[i];
    }

    std::stringstream output;
    for (const auto& c : message) {
        output << (match[c] ? : c);
    }

    std::cout << output.str() << std::endl;

    return 0;
}
