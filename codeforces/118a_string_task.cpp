// http://codeforces.com/problemset/problem/118/A
#include <algorithm>
#include <sstream>
#include <iostream>

std::string algorithm(const std::string& input)
{
    std::string line{input};
    std::stringstream output;

    std::transform(line.begin(), line.end(), line.begin(), ::tolower);

    std::string vowels = {'a', 'o', 'y', 'e', 'u', 'i'};
    for (const auto& c : line) {
        if (vowels.find(c) == std::string::npos) {
            output << "." << c;
        }
    }

    return output.str();
}

int main(int argc, char* argv[])
{
    std::string input;
    std::cin >> input;

    std::cout << algorithm(input) << std::endl;

    return 0;
}
