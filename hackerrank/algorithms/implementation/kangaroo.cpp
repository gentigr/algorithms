// https://www.hackerrank.com/challenges/kangaroo
#include <iostream>

bool will_meet(int x1, int v1, int x2, int v2)
{
    if ((x1 > x2 && v1 >= v2)
            || (x2 > x1 && v2 >= v1)) {
        return false;
    }

    return abs(x1 - x2) % abs(v1 - v2) == 0;
}

int main()
{
    int x1, v1;
    std::cin >> x1 >> v1;
    int x2, v2;
    std::cin >> x2 >> v2;

    std::cout << (will_meet(x1, v1, x2, v2) ? "YES" : "NO") << std::endl;

    return 0;
}
