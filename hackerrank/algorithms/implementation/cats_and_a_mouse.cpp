// https://www.hackerrank.com/challenges/cats-and-a-mouse
#include <cmath>
#include <iostream>

int main()
{
    int q;
    std::cin >> q;

    for(int x, y, z; q-- > 0 && std::cin >> x >> y >> z;) {
        if (abs(x - z) == abs(y - z)) {
            std::cout << "Mouse C" << std::endl;
        }
        else if (abs(x - z) > abs(y - z)) {
            std::cout << "Cat B" << std::endl;
        }
        else {
            std::cout << "Cat A" << std::endl;
        }
    }

    return 0;
}
