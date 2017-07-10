// http://codeforces.com/problemset/problem/266/A
#include <iostream>

int main(int argc, char* argv[])
{
    int16_t n;
    std::cin >> n;

    int16_t stones_count = 0;
    char previous_stone = 0;
    char current_stone;
    for(std::cin >> current_stone;
            n-- > 0;
            previous_stone = current_stone, std::cin >> current_stone) {
        stones_count += (previous_stone == current_stone);
    }

    std::cout << stones_count << std::endl;

    return 0;
}
