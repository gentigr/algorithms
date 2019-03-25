// https://www.hackerrank.com/challenges/tutorial-intro
#include <iostream>

// of course, it is possible to use binary search here,
// but if we may not to read all data, why we must do that?
int main()
{
    int value;
    std::cin >> value;
    int count;
    std::cin >> count;

    for (int i = 0; count-- != 0; ++i) {
        int number;
        std::cin >> number;
        if (value == number) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
