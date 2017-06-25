#include <map>

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

//makes the bots moves for the turn
void Bot::makeMoves()
{
    state.bug << "turn " << state.turn << ":" << endl;
    state.bug << state << endl;
    static auto weights = vector<vector<double>>(state.rows, vector<double>(state.cols, 0.0));
    for(auto& row: weights)
    {
        for(auto& column: row)
        {
            column *= 0.9;
        }
    }

    //picks out moves for each ant
    for(int ant=0; ant<(int)state.myAnts.size(); ant++)
    {
        int direction;
        Location target;
        std::map<int, Location> directions;
        for(int d=0; d<TDIRECTIONS; d++)
        {
            Location loc = state.getLocation(state.myAnts[ant], d);

            if(!state.grid[loc.row][loc.col].isWater)
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
