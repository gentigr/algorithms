//https://www.hackerrank.com/challenges/breaking-best-and-worst-records
#include <climits>
#include <iostream>

int main()
{
    int count;
    std::cin >> count;

    // -1 because first initialization will also counts
    int brake_high_times = -1, brake_low_times = -1;
    long long int highest = LLONG_MIN, lowest = LLONG_MAX;
    for (int score; count-- > 0 && std::cin >> score;) {
        if (score > highest) {
            ++brake_high_times;
            highest = score;
        }
        if (score < lowest) {
            ++brake_low_times;
            lowest = score;
        }
    }

    std::cout << brake_high_times << " " << brake_low_times << std::endl;

    return 0;
}
