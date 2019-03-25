// https://www.hackerrank.com/challenges/icecream-parlor/problem
#include <vector>
#include <iostream>
#include <algorithm>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

struct IceCream {
    int flavor;
    int index;
};

static int binary_search(int first, int last,
                         const std::vector<IceCream>& arr, int search)
{
    if (arr[first].flavor == search || arr[last].flavor == search) {
        return (arr[first].flavor == search ? arr[first] : arr[last]).index;
    }
    if (last - first <= 1) {
        return -1;
    }
    int diff = (last - first) / 2;
    if (arr[first + diff].flavor >= search) {
        return binary_search(first, first + diff, arr, search);
    } else {
        return binary_search(last - diff, last, arr, search);
    }
}

int main()
{
    int t;
    std::cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, m;
        std::cin >> m >> n;
        std::vector<IceCream> arr;
        arr.reserve(n);

        for (int i = 0, cost; i < n && std::cin >> cost; ++i) {
            arr.push_back(IceCream{cost, i + 1});
        }

        // NOTE: modify algorithm to use counting sort if
        //       you have any issues with performance
        auto compare = [](IceCream & a, IceCream & b) {
            return a.flavor < b.flavor;
        };
        std::sort(arr.begin(), arr.end(), compare);
        for (int i = 0; i < n - 1; ++i) {
            int search = m - arr[i].flavor;
            if (search >= arr[i].flavor) {
                int index = binary_search(i + 1, n - 1, arr, search);
                if (index != -1) {
                    std::cout << std::min(arr[i].index, index) << " "
                              << std::max(arr[i].index, index) << std::endl;
                    break;

                }
            }
        }

    }
    return 0;
}

#pragma GCC diagnostic pop
