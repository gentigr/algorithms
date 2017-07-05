// http://codeforces.com/problemset/problem/339/A
#include <map>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[])
{
    std::string example;
    std::cin >> example;

    std::string item;
    std::stringstream input(example);
    std::map<std::string, size_t> parsed;
    while(std::getline(input, item, '+')) {
        parsed[item]++;
    }

    // krunch for saving memory (I mean it is not necessary to use accumulate/copy here)
    bool first = true;
    for(const auto& kv : parsed) {
        for(size_t i = 0; i < kv.second; i++) {
            std::cout << (first ? "" : "+") << kv.first;
            first = false;
        }
    }
    std::cout << std::endl;

    return 0;
}
