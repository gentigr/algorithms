// http://codeforces.com/problemset/problem/50/A
#include <iostream>

int algorithm(int n, int m)
{
    return n * m / 2;
}

int main(int argc, char* argv[])
{
    int n;
    int m;
    std::cin >> n >> m;

    std::cout << algorithm(n, m) << std::endl;

    return 0;
}
