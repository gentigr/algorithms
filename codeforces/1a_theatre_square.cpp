// http://codeforces.com/problemset/problem/1/A
#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[])
{
    double n;
    double m;
    double a;

    std::cin >> n >> m >> a;
    std::cout << std::fixed << std::setprecision(0)
              << ceil(n / a) * ceil(m / a) << std::endl;

    return 0;
}
