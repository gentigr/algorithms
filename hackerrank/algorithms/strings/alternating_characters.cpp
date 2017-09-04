// https://www.hackerrank.com/challenges/alternating-characters
#include <iostream>

int main()
{
    int t;
    std::cin >> t;

    for(std::string s; t-- > 0 && std::cin >> s;) {
        int count = 0;
        char prev = 0;
        for(char c : s) {
            count += (prev == c);
            prev = c;
        }
        std::cout << count << std::endl;
    }

    return 0;
}
