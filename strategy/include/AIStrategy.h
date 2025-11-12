#ifndef AISTRATEGY_H
#define AISTRATEGY_H

#include <vector>
#include <utility>
#include <string>

enum class Player { NONE, X, O };

class TicTacToeGame;

class AIStrategy {
public:
    virtual ~AIStrategy() {}
    virtual std::pair<int, int> makeMove(const TicTacToeGame& game, Player player);
    virtual std::string getName() const = 0;
};

#endif