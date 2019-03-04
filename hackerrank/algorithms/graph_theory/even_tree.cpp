// https://www.hackerrank.com/challenges/even-tree
#include <map>
#include <vector>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> edges_to_parent;
    std::vector<int> count_of_under_nodes{};
    count_of_under_nodes.reserve(n + 1); // just to make arithmetic easier here
    for(int i = 0, v, e; i < n && std::cin >> v >> e; ++i) {
        edges_to_parent[v] = e;
        while(e != 1) {
            count_of_under_nodes[e]++;
            e = edges_to_parent[e];
        }
    }

    int count = 0;
    for(int i = 1; i < n + 1; ++i) {
        count += (count_of_under_nodes[i] % 2 != 0);
    }

    std::cout << count << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
