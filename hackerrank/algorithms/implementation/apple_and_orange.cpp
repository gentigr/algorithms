// https://www.hackerrank.com/challenges/apple-and-orange
#include <iostream>

int main()
{
    int s, t;
    std::cin >> s >> t;
    int a, b;
    std::cin >> a >> b;
    int m, n;
    std::cin >> m >> n;

    int apples = 0, oranges = 0;
    for(int position; m != 0 && std::cin >> position; --m) {
        apples += (position + a >= s && position + a <= t);
    }

    for(int position; n != 0 && std::cin >> position; --n) {
        oranges += (position + b >= s && position + b <= t);
    }

    std::cout << apples << std::endl;
    std::cout << oranges << std::endl;

    return 0;
}
