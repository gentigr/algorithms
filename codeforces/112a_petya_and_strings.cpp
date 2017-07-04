// http://codeforces.com/problemset/problem/112/A
#include <algorithm>
#include <iostream>

int main(int argc, char* argv[])
{
    std::string first;
    std::string second;
    std::cin >> first >> second;

    std::transform(first.begin(), first.end(), first.begin(), ::tolower);
    std::transform(second.begin(), second.end(), second.begin(), ::tolower);

    long long int res = first.compare(second);
    std::cout << (res < 0 ? -1 : (res > 0 ? 1 : 0)) << std::endl;

    return 0;
}
