// http://codeforces.com/problemset/problem/4/A
#include <iostream>

int main(int argc, char* argv[])
{
    uint16_t w;

    std::cin >> w;
    std::cout << ((w > 2 && w % 2 == 0)? "YES" : "NO") << std::endl;

    return 0;
}
