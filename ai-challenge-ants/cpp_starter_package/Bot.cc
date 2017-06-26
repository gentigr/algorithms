#include <map>
#include <climits>

#include "Bot.h"

using namespace std;

//constructor
Bot::Bot()
{

};

//plays a single game of Ants.
void Bot::playGame()
{
    //reads the game parameters and sets up
    cin >> state;
    state.setup();
    endTurn();

    //continues making moves while the game is not over
    while (cin >> state) {
        state.updateVisionInformation();
        makeMoves();
        endTurn();
    }
};

void Bot::normalize(std::vector<std::vector<double>>& weights)
{
    int max = INT_MIN;
    for (auto& row : weights) {
        for (auto& column : row) {
            if (column > max) {
                max = column;
            }
        }
    }
    for (auto& row : weights) {
        for (auto& column : row) {
            column /= max;
        }
    }
}

void Bot::updateMap(std::vector<std::vector<double>>& weights,
                    const std::vector<Location>& hills,
                    int size)
{
    for (auto& row : weights) {
        for (auto& column : row) {
            column *= 0.95;
        }
    }
}

void Bot::homester(State& st,
                   std::vector<std::vector<double>>& weights,
                   const Location& ant,
                   const Location& hill)
{
    int direction;
    Location target;
    std::map<int, Location> directions;
    for (int d = 0; d < TDIRECTIONS; d++) {
        Location loc = st.getLocation(ant, d);

        if (!st.grid[loc.row][loc.col].isWater) {
            directions[d] = loc;
            direction = d;
            target = loc;
        }
    }

    std::map<int, Location> inborders;
    for (const auto& kv : directions) {
        if (sqrt(pow(kv.second.row - hill.row, 2) + pow(kv.second.col - hill.col, 2)) < 6) {
            inborders[kv.first] = kv.second;
        }
    }

    if (inborders.size() == 0) {
        double euklid = LONG_MAX;
        for (const auto& kv : directions) {
            double length = sqrt(pow(kv.second.row - hill.row, 2) + pow(kv.second.col - hill.col, 2));
            if (euklid > length) {
                euklid = length;
                direction = kv.first;
                target = kv.second;
            }
        }
    }

    for (const auto& kv : inborders) {
        if (weights[kv.second.row][kv.second.col] < weights[target.row][target.col]) {
            direction = kv.first;
            target = kv.second;
        }
    }

    weights[target.row][target.col] += 0.1;
    st.makeMove(ant, direction);
}

void Bot::scout(State& st,
                std::vector<std::vector<double>>& weights,
                const Location& ant)
{
    int direction;
    Location target;
    std::map<int, Location> directions;
    for (int d = 0; d < TDIRECTIONS; d++) {
        Location loc = st.getLocation(ant, d);

        if (!st.grid[loc.row][loc.col].isWater) {
            directions[d] = loc;
            direction = d;
            target = loc;
        }
    }

    for (const auto& kv : directions) {
        if (weights[kv.second.row][kv.second.col] < weights[target.row][target.col]) {
            direction = kv.first;
            target = kv.second;
        }
    }

    weights[target.row][target.col] += 0.1;
    st.makeMove(ant, direction);
}

void Bot::hunter(State& st,
                 std::vector<std::vector<double>>& weights,
                 const Location& ant,
                 const std::vector<Location> enemyHills)
{
    // TODO: remove hill from target hills vector when achieve it
    int direction;
    Location target;
    std::map<int, Location> directions;
    static std::vector<Location> targetHills;
    static auto attacks = vector<vector<double>>(state.rows, vector<double>(state.cols, 0.0));

    for (int d = 0; d < TDIRECTIONS; d++) {
        Location loc = st.getLocation(ant, d);

        if (!st.grid[loc.row][loc.col].isWater) {
            directions[d] = loc;
            direction = d;
            target = loc;
        }
    }

    if (enemyHills.size() > 0) {
        for (const auto& hill : enemyHills) {
            for (const auto& target : targetHills) {
                if (target.row == hill.row && target.col == hill.col) {
                    break;
                }
                targetHills.push_back(hill);
            }
        }
    }

    if (targetHills.size() > 0) {
        for (const auto& hill : targetHills) {
            for (int i = 0; i < weights.size(); i++) {
                for (int j = 0; j < weights[0].size(); j++) {
                    attacks[i][j] += 0.1 * (abs(i - hill.row) + abs(j - hill.col)) / targetHills.size();
                }
            }
        }
        this->normalize(attacks);

        for (const auto& kv : directions) {
            double suggested = weights[kv.second.row][kv.second.col] + attacks[kv.second.row][kv.second.col];
            double previous = weights[target.row][target.col] + attacks[target.row][target.col];
            if (suggested < previous) {
                direction = kv.first;
                target = kv.second;
            }
        }
    } else {
        for (const auto& kv : directions) {
            if (weights[kv.second.row][kv.second.col] < weights[target.row][target.col]) {
                direction = kv.first;
                target = kv.second;
            }
        }
    }

    weights[target.row][target.col] += 0.1;
    st.makeMove(ant, direction);
}

//makes the bots moves for the turn
void Bot::makeMoves()
{
    state.bug << "turn " << state.turn << ":" << endl;
    state.bug << state << endl;
    static auto weights = vector<vector<double>>(state.rows, vector<double>(state.cols, 0.0));
    this->updateMap(weights, state.myHills, state.myAnts.size());

    //picks out moves for each ant
    for (int ant = 0; ant < (int)state.myAnts.size(); ant++) {
        if (ant < state.myHills.size()) {
            this->homester(state, weights, state.myAnts[ant], state.myHills[ant]);
        } else if (ant >= state.myHills.size() && ant < 11) {
            this->scout(state, weights, state.myAnts[ant]);
        } else {
            this->hunter(state, weights, state.myAnts[ant], state.enemyHills);
        }
    }

    state.bug << "time taken: " << state.timer.getTime() << "ms" << endl << endl;
};

//finishes the turn
void Bot::endTurn()
{
    if (state.turn > 0) {
        state.reset();
    }
    state.turn++;

    cout << "go" << endl;
};
