#ifndef BOT_H_
#define BOT_H_

#include "State.h"

/*
    This struct represents your bot in the game of Ants
*/
struct Bot
{
    State state;

    Bot();

    void playGame();    //plays a single game of Ants

    void makeMoves();   //makes moves for a single turn
    void endTurn();     //indicates to the engine that it has made its moves

    bool investigator(int size);
    bool conservator(int row, int col, const std::vector<Location>& hills);

    void updateMap(std::vector<std::vector<double>>& weights, const std::vector<Location>& hills, int size);
    void normalize(std::vector<std::vector<double>>& weights);
};

#endif //BOT_H_
