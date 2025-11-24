#include "EasyAI.h"
#include "TicTacToeGame.h"
#include <random>

std::pair<int, int> EasyAI::makeMove(const TicTacToeGame& game, Player player) {
    // usar para evitar warning
    (void)player;
    
    std::vector<std::pair<int, int>> availableMoves;
    
    // Encontrar todas las casillas vacias
    auto board = game.getBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player::NONE) {
                availableMoves.push_back({i, j});
            }
        }
    }
    
    // Elegir movimiento aleatorio
    if (!availableMoves.empty()) {
        std::uniform_int_distribution<> dis(0, availableMoves.size() - 1);
        return availableMoves[dis(gen)];
    }
    
    return {-1, -1};
}