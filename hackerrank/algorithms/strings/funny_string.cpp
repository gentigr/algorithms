// https://www.hackerrank.com/challenges/funny-string
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"

int main()
{
    int t;
    std::cin >> t;

    for(std::string s; t-- > 0 && std::cin >> s;) {
        bool valid = true;
        for(int i = 1; i < s.size() / 2 + 1 && valid; i++) {
            if (abs(s[i] - s[i - 1]) != abs(s[s.size() - i - 1] - s[s.size() - i])) {
                valid = false;
            }
        }
        std::cout << (valid ? "Funny" : "Not Funny") << std::endl;
    }

    return 0;
}

#pragma GCC diagnostic pop
