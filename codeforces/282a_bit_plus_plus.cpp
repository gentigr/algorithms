// http://codeforces.com/problemset/problem/282/A
#include <iostream>

long long int parser(const std::string& command, long long int x)
{
    if (command == "X++" || command == "++X") {
        return x + 1;
    } else if (command == "X--" || command == "--X") {
        return x - 1;
    }

    // impossible case according to task, it is allowed to use even assert here
    return x;
}

int main(int argc, char* argv[])
{
    int n;
    std::string instruction;
    long long int x = 0;

    std::cin >> n;
    while(n-- > 0) {
        std::cin >> instruction;
        x = parser(instruction, x);
    }

    std::cout << x << std::endl;

    return 0;
}
