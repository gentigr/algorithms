// https://www.hackerrank.com/challenges/reduced-string
#include <vector>
#include <iostream>

int main()
{
    std::string input;
    std::cin >> input;

    std::vector<char> data;
    for(const auto& ch : input) {
        if (data.size() > 0 && data.back() == ch) {
            data.pop_back();
        } else {
            data.push_back(ch);
        }
    }

    std::string output;
    for(const auto& ch : data) {
        output += ch;
    }

    std::cout << (output.size() > 0 ? output : "Empty String") << std::endl;

    return 0;
}
