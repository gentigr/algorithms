// http://codeforces.com/problemset/problem/133/A
#include <iostream>
#include <algorithm>

bool is_appropriate(const char c)
{
    return c == 'H' || c == 'Q' || c == '9';
};

int main(int argc, char* argv[])
{
    std::string instructions;
    std::cin >> instructions;

    auto res = std::find_if(instructions.cbegin(), instructions.cend(), is_appropriate);
    std::cout << (res != instructions.end() ? "YES" : "NO") << std::endl;

    return 0;
}
