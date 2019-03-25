// https://www.hackerrank.com/challenges/bon-appetit/problem
#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    int cost = 0;
    for (int number; n-- > 0 &&
            std::cin >> number; cost += (k-- == 0 ? 0 : number));

    int b;
    std::cin >> b;
    std::cout << (cost / 2 == b ? "Bon Appetit" : std::to_string(
                          b - cost / 2)) << std::endl;

    return 0;
}
