// http://codeforces.com/problemset/problem/96/A
#include <iostream>

#define PLAYERS_IN_ROW 7

bool is_dangerous(const std::string& players)
{
    int row_count = 0;

    for(int i = 0, previous = -1;
            i < players.size() && row_count < PLAYERS_IN_ROW - 1;
            previous = players[i], i++) {
        row_count = (players[i] == previous) ? row_count + 1 : 0;
    }

    return row_count == PLAYERS_IN_ROW - 1;
}

int main(int argc, char* argv[])
{
    std::string players;
    std::cin >> players;

    std::cout << (is_dangerous(players)? "YES" : "NO") << std::endl;

    return 0;
}
