// https://www.hackerrank.com/challenges/torque-and-development
#include <set>
#include <iostream>
#include <unordered_map>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

template<typename T>
T evaluate_minimal_cost(T towns_count, T library_cost, T road_cost, std::unordered_map<T, std::set<T>>& roads)
{
    if (library_cost <= road_cost) {
        return library_cost * roads.size();
    }

    int library_groups = 0;
    std::set<T> discarded_towns;
    while(roads.size() > 0) {
        discarded_towns.insert(roads.begin()->first);

        while(discarded_towns.size() > 0) {
            std::set<T> new_discarded_towns;
            for(const auto& town : discarded_towns) {
                for(const auto& target : roads[town]) {
                    new_discarded_towns.insert(target);
                }
                roads.erase(town);
            }
            discarded_towns = new_discarded_towns;
        }
        library_groups++;
    }

    return library_groups * library_cost + road_cost * (towns_count - library_groups);
}

int main()
{
    int size;
    std::cin >> size;

    long long int town_count;
    long long int roads_count;
    long long int library_cost;
    long long int road_cost;
    std::unordered_map<long long int, std::set<long long int>> roads;

    while(size-- != 0) {
        std::cin >> town_count >> roads_count >> library_cost >> road_cost;
        roads.clear();
        for(int i = 1; i <= town_count; ++i) {
            roads[i].insert(i);
        }
        for(int start, end, i = 1; i <= roads_count; ++i) {
            std::cin >> start >> end;
            roads[start].insert(end);
            roads[end].insert(start);
        }

        std::cout << evaluate_minimal_cost(town_count, library_cost, road_cost, roads) << std::endl;
    }

    return 0;
}

#pragma GCC diagnostic pop
