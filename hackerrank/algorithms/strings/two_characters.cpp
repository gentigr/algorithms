// https://www.hackerrank.com/challenges/two-characters
#include <set>
#include <iostream>
#include <algorithm>

static int sequence_length(std::string& input, char first, char second)
{
    int count = 0;
    char previous = '\0';
    for(char ch : input) {
        if (ch == first || ch == second) {
            if (previous == ch) {
                return -1;
            }

            previous = ch;
            ++count;
        }
    }

    return count;
}

static int max_sequence_length(std::string& input)
{
    std::set<char> unique_letters;
    for(char c : input) {
        unique_letters.insert(c);
    }

    int max = 0;
    for(auto iti = unique_letters.begin(); iti != std::prev(unique_letters.end()); ++iti) {
        for(auto itj = std::next(iti); itj != unique_letters.end(); ++itj) {
            int result = sequence_length(input, *iti, *itj);
            max = (result > max ? result : max);
        }
    }

    return max;
}

int main()
{
    int n;
    std::string input;
    std::cin >> n >> input;

    std::cout << max_sequence_length(input) << std::endl;

    return 0;
}
