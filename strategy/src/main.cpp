#include "TicTacToeGame.h"
#include "EasyAI.h"
#include "MediumAI.h"
#include "HardAI.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "--- TRES EN RAYA CON IA ---" << std::endl;
    
    int choice;
    std::cout << "\nSelecciona dificultad:" << std::endl;
    std::cout << "1. Facil" << std::endl;
    std::cout << "2. Medio" << std::endl;
    std::cout << "3. Dificil" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> choice;
    
    TicTacToeGame game;
    
    switch (choice) {
        case 1:
            game.setAIStrategy(std::make_unique<EasyAI>());
            break;
        case 2:
            game.setAIStrategy(std::make_unique<MediumAI>());
            break;
        case 3:
            game.setAIStrategy(std::make_unique<HardAI>());
            break;
        default:
            std::cout << "Opcion invalida, usando IA Facil por defecto." << std::endl;
            game.setAIStrategy(std::make_unique<EasyAI>());
    }
    
    game.playGame();
    
    return 0;
}