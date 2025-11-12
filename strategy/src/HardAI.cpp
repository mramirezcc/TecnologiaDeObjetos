#include "HardAI.h"
#include "TicTacToeGame.h"
#include <climits>
#include <iostream>

std::pair<int, int> HardAI::makeMove(const TicTacToeGame& game, Player player) {
    auto board = game.getBoard();
    int bestScore = INT_MIN;
    std::pair<int, int> bestMove = {-1, -1};
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player::NONE) {
                board[i][j] = player;
                int score = minimax(board, player, false);
                board[i][j] = Player::NONE;
                
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }
    
    return bestMove;
}

int HardAI::minimax(std::vector<std::vector<Player>>& board, Player player, bool isMaximizing) {
    int score = evaluateBoard(board);
    
    if (score == 10) return score;
    if (score == -10) return score;
    if (!isMovesLeft(board)) return 0;
    
    if (isMaximizing) {
        int best = INT_MIN;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == Player::NONE) {
                    board[i][j] = player;
                    best = std::max(best, minimax(board, player, !isMaximizing));
                    board[i][j] = Player::NONE;
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        Player opponent = (player == Player::X) ? Player::O : Player::X;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == Player::NONE) {
                    board[i][j] = opponent;
                    best = std::min(best, minimax(board, player, !isMaximizing));
                    board[i][j] = Player::NONE;
                }
            }
        }
        return best;
    }
}

int HardAI::evaluateBoard(const std::vector<std::vector<Player>>& board) {
    // Verificar todo
    for (int i = 0; i < 3; ++i) {
        // Filas
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == Player::X) return 10;
            else if (board[i][0] == Player::O) return -10;
        }
        // Columnas
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == Player::X) return 10;
            else if (board[0][i] == Player::O) return -10;
        }
    }
    
    // Diagonales
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == Player::X) return 10;
        else if (board[0][0] == Player::O) return -10;
    }
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == Player::X) return 10;
        else if (board[0][2] == Player::O) return -10;
    }
    
    return 0;
}

bool HardAI::isMovesLeft(const std::vector<std::vector<Player>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player::NONE) return true;
        }
    }
    return false;
}