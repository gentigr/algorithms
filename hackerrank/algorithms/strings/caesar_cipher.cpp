// https://www.hackerrank.com/challenges/caesar-cipher-1
#include <string>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

// ASCII: [65, 90] == ['A', 'Z'] , [97, 122] == ['a', 'z']
// 25 == 'Z' - 'A' == 'z' - 'a'
static char caesar_cipher(char c, int k)
{
    if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + k) % ('Z' - 'A' + 1)) + 'A';
    } else if (c >= 'a' && c <= 'z') {
        return ((c - 'a' + k) % ('Z' - 'A' + 1)) + 'a';
    }

    return c;
}

int main()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int k;
    std::cin >> k;

    for (int i = 0; i < s.size(); ++i) {
        s[i] = caesar_cipher(s[i], k);
    }

    std::cout << s << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
