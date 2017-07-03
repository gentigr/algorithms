// http://codeforces.com/problemset/problem/231/A
#include <iostream>

int main(int argc, char* argv[])
{
    int n;
    int petya;
    int vasya;
    int tonya;
    int solved_count = 0;

    std::cin >> n;
    while(n-- > 0) {
        std::cin >> petya >> vasya >> tonya;
        solved_count += (petya + vasya + tonya > 1);
    }

    std::cout << solved_count << std::endl;

    return 0;
}
