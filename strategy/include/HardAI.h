#ifndef HARDAI_H
#define HARDAI_H

#include "AIStrategy.h"

class HardAI : public AIStrategy {
public:
    HardAI() = default;
    ~HardAI() override = default;
    
    std::pair<int, int> makeMove(const TicTacToeGame& game, Player player) override;
    std::string getName() const override { return "IA Dificil"; }
    
private:
    int minimax(std::vector<std::vector<Player>>& board, Player player, bool isMaximizing);
    int evaluateBoard(const std::vector<std::vector<Player>>& board);
    bool isMovesLeft(const std::vector<std::vector<Player>>& board);
};

#endif