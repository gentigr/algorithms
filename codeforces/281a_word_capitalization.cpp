// http://codeforces.com/problemset/problem/281/A
#include <iostream>

int main(int argc, char* argv[])
{
    std::string word;
    std::cin >> word;

    word[0] = toupper(word[0]);
    std::cout << word << std::endl;

    return 0;
}
