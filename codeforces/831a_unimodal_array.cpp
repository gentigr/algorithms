// http://codeforces.com/problemset/problem/831/A
#include <iostream>

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    enum Mode { UP, CONST, DOWN };
    int mode = Mode::UP;
    int previous_a = -1;
    bool good_sequence = true;
    for (int i = 0, a = 0; i < n && good_sequence; i++, previous_a = a) {
        std::cin >> a;
        if ((a > previous_a && mode == Mode::UP)
                || (a == previous_a && mode == Mode::CONST)
                || (a < previous_a && mode == Mode::DOWN)) {
        } else if (a == previous_a && mode == Mode::UP) {
            mode = Mode::CONST;
        } else if (a < previous_a && (mode == Mode::UP || mode == Mode::CONST)) {
            mode = Mode::DOWN;
        } else {
            good_sequence = false;
        }
    }

    std::cout << (good_sequence ? "YES" : "NO")
              << std::endl;

    return 0;
}
