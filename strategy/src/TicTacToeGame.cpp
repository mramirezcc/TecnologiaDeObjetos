#include "TicTacToeGame.h"
#include "EasyAI.h"
#include "MediumAI.h"
#include "HardAI.h"
#include <iostream>
#include <limits>

TicTacToeGame::TicTacToeGame() {
    resetGame();
    // Estrategia por defecto
    aiStrategy = std::make_unique<EasyAI>();
}

void TicTacToeGame::setAIStrategy(std::unique_ptr<AIStrategy> strategy) {
    aiStrategy = std::move(strategy);
}

void TicTacToeGame::playGame() {
    std::cout << "=== TRES EN RAYA ===" << std::endl;
    std::cout << "Estrategia actual: " << aiStrategy->getName() << std::endl;
    std::cout << "Tu eres: X | IA es: O" << std::endl << std::endl;
    
    while (true) {
        displayBoard();
        
        if (currentPlayer == Player::X) {
            // Turno del jugador humano
            int row, col;
            std::cout << "Tu turno (fila columna: 0 0 a 2 2): ";
            std::cin >> row >> col;
            
            if (!std::cin || row < 0 || row > 2 || col < 0 || col > 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Movimiento invalido! Intenta de nuevo." << std::endl;
                continue;
            }
            
            if (!makeMove(row, col, Player::X)) {
                std::cout << "Casilla ocupada! Intenta de nuevo." << std::endl;
                continue;
            }
        } else {
            // Turno de la IA
            std::cout << "Turno de la IA (" << aiStrategy->getName() << ")..." << std::endl;
            auto move = aiStrategy->makeMove(*this, Player::O);
            makeMove(move.first, move.second, Player::O);
            std::cout << "La IA jugo en: " << move.first << " " << move.second << std::endl;
        }
        
        // Verificar fin del juego
        if (checkWin(currentPlayer)) {
            displayBoard();
            std::cout << (currentPlayer == Player::X ? "¡Ganaste!" : "¡La IA gana!") << std::endl;
            break;
        }
        
        if (isBoardFull()) {
            displayBoard();
            std::cout << "¡Empate!" << std::endl;
            break;
        }
        
        switchPlayer();
    }
}

bool TicTacToeGame::makeMove(int row, int col, Player player) {
    if (!isValidMove(row, col)) return false;
    
    board[row][col] = player;
    return true;
}

void TicTacToeGame::displayBoard() const {
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char symbol = ' ';
            if (board[i][j] == Player::X) symbol = 'X';
            else if (board[i][j] == Player::O) symbol = 'O';
            
            std::cout << " " << symbol << " ";
            if (j < 2) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "-----------" << std::endl;
    }
    std::cout << std::endl;
}

bool TicTacToeGame::checkWin(Player player) const {
    // Verificar filas y columnas
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    
    // Verificar diagonales
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}

bool TicTacToeGame::isBoardFull() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == Player::NONE) return false;
        }
    }
    return true;
}

bool TicTacToeGame::isValidMove(int row, int col) const {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == Player::NONE;
}

void TicTacToeGame::switchPlayer() {
    currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
}

void TicTacToeGame::resetGame() {
    board = std::vector<std::vector<Player>>(3, std::vector<Player>(3, Player::NONE));
    currentPlayer = Player::X;
}