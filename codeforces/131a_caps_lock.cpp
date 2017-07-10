// http://codeforces.com/problemset/problem/131/A
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::string word;
    std::cin >> word;

    std::string uppered{word};
    std::transform(word.cbegin(), word.cend(), uppered.begin(), ::toupper);

    if (word == uppered) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    } else if (word[0] == ::tolower(word[0]) &&
               word.compare(1, word.size(), uppered, 1, uppered.size()) == 0) {
        std::transform(word.begin() + 1, word.end(), word.begin() + 1, ::tolower);
        word[0] = ::toupper(word[0]);
    }

    std::cout << word << std::endl;

    return 0;
}
