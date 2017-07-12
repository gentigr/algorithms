// http://codeforces.com/problemset/problem/263/A
#include <iostream>

#define SIZE 5

int main(int argc, char* argv[])
{
    int x = 0;
    int y = 0;
    int one = 0;
    for (x = 0; x < SIZE && one != 1; ++x) {
        for (y = 0; y < SIZE && one != 1; ++y, std::cin >> one) {
        }
    }

    std::cout << (abs(3 - x) + abs(3 - y)) << std::endl;

    return 0;
}
