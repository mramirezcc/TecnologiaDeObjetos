#ifndef EASYAI_H
#define EASYAI_H

#include "AIStrategy.h"
#include <random>

class EasyAI : public AIStrategy {
public:
    EasyAI() = default;
    ~EasyAI() override;
    
    std::pair<int, int> makeMove(const TicTacToeGame& game, Player player) override;
    std::string getName() const override { return "IA Facil"; }
    
private:
    std::random_device rd;
    std::mt19937 gen{rd()};
};

#endif