//http://codeforces.com/problemset/problem/71/A
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    uint16_t n;

    std::cin >> n;

    std::vector<std::string> words(n);
    while (n-- > 0) {
        std::string word;
        std::cin >> word;
        if (word.size() > 10) {
            words.push_back(word[0] + std::to_string(word.size() - 2) + word[word.size() - 1]);
        } else {
            words.push_back(word);
        }
    }

    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
