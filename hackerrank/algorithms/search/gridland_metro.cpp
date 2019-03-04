// https://www.hackerrank.com/challenges/gridland-metro/problem
#include <map>
#include <vector>
#include <utility>
#include <iostream>

static std::vector<std::pair<long long, long long>>
        find_new_regions(const std::map<long long, long long>& regions,
                         long long start,
                         long long end)
{
    bool covered = false;
    std::vector<std::pair<long long, long long>> new_regions;
    for(auto it = regions.begin(); it != regions.end() && !covered; ++it) {
        if (start < it->first) {
            if (end < it->first) {
                new_regions.push_back(std::make_pair(start, end));
                covered = true;
            } else if (end <= it->second) {
                new_regions.push_back(std::make_pair(start, it->first - 1));
                covered = true;
            } else if (end > it->second) {
                new_regions.push_back(std::make_pair(start, it->first - 1));
                start = it->second + 1;
            }
        } else if (start >= it->first) {
            if (end <= it->second) {
                covered = true;
            } else if (start <= it->second && end > it->second) {
                start = it->second + 1;
            }
        }
    }
    if (!covered) {
        new_regions.push_back(std::make_pair(start, end));
    }

    return new_regions;
}

int main()
{
    long long n, m, k;
    std::cin >> n >> m >> k;

    long long engaged_space = 0;
    std::map<long long, std::map<long long, long long>> grid{};
    for(long long row, s, e; k-- > 0 && std::cin >> row >> s >> e; ) {
        auto new_regions = find_new_regions(grid[row], s, e);

        long long count = 0;
        for(auto& r : new_regions) {
            count += (r.second - r.first + 1);
            grid[row][r.first] = r.second;
        }
        engaged_space += count;
    }

    std::cout << (n * m - engaged_space) << std::endl;

    return 0;
}
