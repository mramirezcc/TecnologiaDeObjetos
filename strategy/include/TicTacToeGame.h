#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include "AIStrategy.h"
#include <vector>
#include <memory>

class TicTacToeGame {
public:
    TicTacToeGame();
    
    void playGame();
    void setAIStrategy(std::unique_ptr<AIStrategy> strategy);
    bool makeMove(int row, int col, Player player);
    void displayBoard() const;
    bool checkWin(Player player) const;
    bool isBoardFull() const;
    Player getCurrentPlayer() const { return currentPlayer; }
    std::vector<std::vector<Player>> getBoard() const { return board; }
    bool isValidMove(int row, int col) const;
    
private:
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    std::unique_ptr<AIStrategy> aiStrategy;
    
    void switchPlayer();
    void resetGame();
};

#endif