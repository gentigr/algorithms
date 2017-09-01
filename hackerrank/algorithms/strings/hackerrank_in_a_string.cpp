// https://www.hackerrank.com/challenges/hackerrank-in-a-string
#include <iostream>

bool is_contain(const std::string& str, const std::string& word)
{
    int i = 0;
    for(int j = 0; j < str.size(); i += (str[j] == word[i]), ++j);

    return i == word.size();
}

int main()
{
    const std::string word {"hackerrank"};

    int q;
    std::cin >> q;

    for(std::string str; q-- > 0 && std::cin >> str;) {
        std::cout << (is_contain(str, word) ? "YES" : "NO") << std::endl;
    }

    return 0;
}
