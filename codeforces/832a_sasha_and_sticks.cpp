// http://codeforces.com/problemset/problem/832/A
#include <iostream>

int main(int argc, char* argv[])
{
    unsigned long long n;
    unsigned long long k;

    std::cin >> n >> k;
    std::cout << (n / k % 2 == 0 ? "NO" : "YES") << std::endl;

    return 0;
}
