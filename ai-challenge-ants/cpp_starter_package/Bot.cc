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
    while(cin >> state)
    {
        state.updateVisionInformation();
        makeMoves();
        endTurn();
    }
};

bool Bot::investigator(int size)
{
    static bool investigator = false;
    if (size > 1)
    {
        investigator = true;
    }
    return investigator || size > 1;
}

bool Bot::conservator(int row, int col, const std::vector<Location>& hills)
{
    for(const auto& hill: hills)
    {
        if (sqrt(pow(row - hill.row, 2) + pow(col - hill.col, 2)) < 5)
        {
            return true;
        }
    }

    return false;
}

void Bot::normalize(std::vector<std::vector<double>>& weights)
{
    int max = INT_MIN;
    for(auto& row: weights)
    {
        for(auto& column: row)
        {
            if (column > max)
            {
                max = column;
            }
        }
    }
    for(auto& row: weights)
    {
        for(auto& column: row)
        {
            column /= max;
        }
    }
}

void print(const std::vector<std::vector<double>>& weights)
{
    std::fstream f;
    f.open("/tmp/mtx.txt", std::fstream::in | std::fstream::app | std::fstream::out);
    for(int i = 0; i < weights.size(); i++)
    {
        for(int j = 0; j < weights[0].size(); j++)
        {
            f << weights[i][j] << ' ';
        }
        f << std::endl;
        f.flush();
    }
    f << std::endl;
    f.close();
}

void Bot::updateMap(std::vector<std::vector<double>>& weights,
                    const std::vector<Location>& hills,
                    int size)
{
    for(auto& row: weights)
    {
        for(auto& column: row)
        {
            column *= 0.9;
        }
    }
    if (size == 1) // conservator
    {
        double mtx[weights.size()][weights[0].size()]{};
        for(const auto& hill: hills)
        {
            for(int i = 0; i < weights.size(); i++)
            {
                for(int j = 0; j < weights[0].size(); j++)
                {
                    mtx[i][j] += 0.1*(abs(i - hill.row) + abs(j - hill.col)) / hills.size();
                }
            }
        }
        for(int i = 0; i < weights.size(); i++)
        {
            for(int j = 0; j < weights[0].size(); j++)
            {
                weights[i][j] += mtx[i][j];
            }
        }
    }
    else if (size > 10) // hunter
    {
    }
}

//makes the bots moves for the turn
void Bot::makeMoves()
{
    state.bug << "turn " << state.turn << ":" << endl;
    state.bug << state << endl;
    static auto weights = vector<vector<double>>(state.rows, vector<double>(state.cols, 0.0));
#if 0
    print(weights);
    this->updateMap(weights, state.myHills, state.myAnts.size());
#endif

    //picks out moves for each ant
    for(int ant=0; ant<(int)state.myAnts.size(); ant++)
    {
        if (ant == 0)
        {
            // homester
        }
        else if (ant > 0 && ant < 11)
        {
            // investigator
        }
        else
        {
            // hunter
        }
        int direction;
        Location target;
        std::map<int, Location> directions;
        for(int d=0; d<TDIRECTIONS; d++)
        {
            Location loc = state.getLocation(state.myAnts[ant], d);

            if(!state.grid[loc.row][loc.col].isWater
                && (investigator(state.myAnts.size())
                    || conservator(loc.row, loc.col, state.myHills)))
            {
                direction = d;
                target = loc;

                directions[d] = loc;
            }
        }

        for(const auto& kv: directions)
        {
            if(weights[kv.second.row][kv.second.col] < weights[target.row][target.col])
            {
                direction = kv.first;
                target = kv.second;
            }
        }

        if (directions.size() > 0)
        {
            weights[target.row][target.col] += 0.1;
            state.makeMove(state.myAnts[ant], direction);
        }
    }

#if 0
    this->normalize(weights);
#endif
    state.bug << "time taken: " << state.timer.getTime() << "ms" << endl << endl;
};

//finishes the turn
void Bot::endTurn()
{
    if(state.turn > 0)
        state.reset();
    state.turn++;

    cout << "go" << endl;
};
