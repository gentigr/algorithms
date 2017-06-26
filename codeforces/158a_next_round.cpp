//http://codeforces.com/problemset/problem/158/A
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    uint16_t n;
    uint16_t k;

    std::cin >> n >> k;

    std::vector<uint16_t> scores;
    while (n-- > 0) {
        uint16_t score;
        std::cin >> score;
        scores.push_back(score);
    }

    if (scores[k - 1] <= 0) {
        uint16_t zero = 0;
        for(auto it = scores.cbegin(); it < scores.cend() && *it != 0; it++, zero++);
        std::cout << zero << std::endl;
    } else {
        uint16_t save = scores[k - 1];
        for(auto it = scores.cbegin() + k; it < scores.cend() && save == *it; it++, k++);
        std::cout << k << std::endl;
    }

    return 0;
}
