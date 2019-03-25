// https://www.hackerrank.com/challenges/pairs/problem
#include <set>
#include <queue>
#include <iostream>

int main()
{
    long int n, k;
    std::cin >> n >> k;

    std::set<long int> seq;
    for (long int num; n-- > 0 && std::cin >> num; seq.insert(num));

    long int count = 0;
    std::queue<long int> accumulator{};
    for (int item : seq) {
        while (!accumulator.empty() && accumulator.front() <= item) {
            count += (accumulator.front() == item);
            accumulator.pop();
        }
        accumulator.push(item + k);
    }

    std::cout << count << std::endl;

    return 0;
}
// NOTE: more conscious solution for this problem consists of using
//       unordered_set for `seq` and than iterating over collection with
//       count += seq.count(*it + k);
