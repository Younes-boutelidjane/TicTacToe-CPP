#include "TicTacToe.h"
#include <iostream>

int main() {
    int choice;
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Player vs Player" << std::endl;
    std::cout << "2. Player vs AI" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    TicTacToe game;

    switch (choice) {
        case 1:
            std::cout << "You chose Player vs Player." << std::endl;
            game.play();
            break;
        case 2:
            std::cout << "You chose Player vs AI." << std::endl;
            game.playAgainstAI();
            break;
        default:
            std::cout << "Invalid choice. Exiting." << std::endl;
            break;
    }

    return 0;
}
