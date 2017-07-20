// http://codeforces.com/problemset/problem/831/C
#include <deque>
#include <iostream>
#include <unordered_set>

int main(int argc, char* argv[])
{
    int k;
    int n;
    std::deque<int> a {0};

    std::cin >> k >> n;
    for (int i = 1, mark; i <= k; i++) {
        std::cin >> mark;
        a.push_back(a[i - 1] + mark);
    }

    a.pop_front(); // remove first zero
    std::unordered_set<int> res;
    for (int i = 0, number; i <= n; i++) {
        std::cin >> number;
        std::unordered_set<int> tset;
        for(int j = 0; j < k; j++) {
            if (i == 0 || res.find(number - a[j]) != res.end()) {
                tset.insert(number - a[j]);
            }
        }
        res = tset;
    }

    std::cout << res.size() << std::endl;

    return 0;
}
