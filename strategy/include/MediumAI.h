#ifndef MEDIUMAI_H
#define MEDIUMAI_H

#include "AIStrategy.h"

class MediumAI : public AIStrategy {
public:
    MediumAI() = default;
    ~MediumAI() override = default;
    
    std::pair<int, int> makeMove(const TicTacToeGame& game, Player player) override;
    std::string getName() const override { return "IA Media"; }
};

#endif