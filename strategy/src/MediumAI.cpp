#include "MediumAI.h"
#include "TicTacToeGame.h"
#include <iostream>

std::pair<int, int> MediumAI::makeMove(const TicTacToeGame& game, Player player) {
    auto board = game.getBoard();
    Player opponent = (player == Player::X) ? Player::O : Player::X;
    
    // Buscar ganar inmediatamente
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player::NONE) {
                // Simular movimiento
                board[i][j] = player;
                TicTacToeGame tempGame;
                // Verificar si gana
                bool wins = false;
                // Verificar filas
                if (board[i][0] == player && board[i][1] == player && board[i][2] == player) wins = true;
                // Verificar columnas
                if (board[0][j] == player && board[1][j] == player && board[2][j] == player) wins = true;
                // Verificar diagonales
                if (i == j && board[0][0] == player && board[1][1] == player && board[2][2] == player) wins = true;
                if (i + j == 2 && board[0][2] == player && board[1][1] == player && board[2][0] == player) wins = true;
                
                board[i][j] = Player::NONE;
                if (wins) return {i, j};
            }
        }
    }
    
    // Bloquear al oponente si puede ganar
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player::NONE) {
                board[i][j] = opponent;
                bool opponentWins = false;
                // Verificar filas
                if (board[i][0] == opponent && board[i][1] == opponent && board[i][2] == opponent) opponentWins = true;
                // Verificar columnas
                if (board[0][j] == opponent && board[1][j] == opponent && board[2][j] == opponent) opponentWins = true;
                // Verificar diagonales
                if (i == j && board[0][0] == opponent && board[1][1] == opponent && board[2][2] == opponent) opponentWins = true;
                if (i + j == 2 && board[0][2] == opponent && board[1][1] == opponent && board[2][0] == opponent) opponentWins = true;
                
                board[i][j] = Player::NONE;
                if (opponentWins) return {i, j};
            }
        }
    }
    
    // Asegurar centro
    if (board[1][1] == Player::NONE) return {1, 1};
    
    // Asegurar esquinas
    std::vector<std::pair<int, int>> corners = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (auto corner : corners) {
        if (board[corner.first][corner.second] == Player::NONE) {
            return corner;
        }
    }
    
    // Cualquier movimiento disponible
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player::NONE) {
                return {i, j};
            }
        }
    }
    
    return {-1, -1};
}