// https://www.hackerrank.com/challenges/counting-valleys
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-default"

int main()
{
    int n;
    std::cin >> n;

    std::string landscape;
    std::cin >> landscape;

    int valley_count = 0;
    int see_level = 0;
    for (char c : landscape) {
        switch (c) {
        case 'D':
            --see_level;
            break;
        case 'U':
            ++see_level;
            valley_count += (see_level == 0);
            break;
        }
    }

    std::cout << valley_count << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
