// http://codeforces.com/problemset/problem/116/A
#include <iostream>

int main(int argc, char* argv[])
{
    int16_t n;
    long long int a;
    long long int b;
    long long int current_capacity = 0;
    long long int max_capacity = 0;

    for(std::cin >> n >> a >> b; n-- > 0; std::cin >> a >> b) {
        current_capacity += (b - a);
        if (current_capacity > max_capacity) {
            max_capacity = current_capacity;
        }
    }

    std::cout << max_capacity << std::endl;

    return 0;
}
