// http://codeforces.com/problemset/problem/58/A
#include <iostream>

int main(int argc, char* argv[])
{
    std::string s;
    std::cin >> s;

    std::string hello {"hello"};

    size_t promoted = 0;
    for(size_t i = 0; i < s.size() && promoted < hello.size(); i++) {
        promoted += (s[i] == hello[promoted])? 1 : 0;
    }

    std::cout << (promoted < hello.size() ? "NO" : "YES") << std::endl;
    return 0;
}
