#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

TicTacToe::TicTacToe() {
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    currentPlayer = 1;
}

void TicTacToe::printBoardWithGraphics() {
    std::string horizontalLine = "-------------";
    std::cout << "   1   2   3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << " " << horizontalLine << std::endl;
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " " << horizontalLine << std::endl;
}

bool TicTacToe::makeMove(int row, int col) {
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
        std::cout << "Invalid move! Try again." << std::endl;
        return false;
    }
    board[row - 1][col - 1] = (currentPlayer == 1) ? 'X' : 'O';
    return true;
}

bool TicTacToe::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true; // Column win
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return true; // Diagonal win
    return false;
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // If any cell is empty, the board is not full
        }
    }
    return true; // If no cell is empty, the board is full
}

void TicTacToe::switchPlayer() {
    currentPlayer *= -1; // Switch player
}

void TicTacToe::play() {
    int row, col;
    while (true) {
        printBoardWithGraphics();
        std::cout << "Player " << ((currentPlayer == 1) ? "X" : "O") << "'s turn. Enter row and column: ";
        std::cin >> row >> col;
        if (makeMove(row, col)) {
            if (checkWin()) {
                printBoardWithGraphics();
                std::cout << "Player " << ((currentPlayer == 1) ? "X" : "O") << " wins!" << std::endl;
                break;
            }
            if (isBoardFull()) {
                printBoardWithGraphics();
                std::cout << "It's a draw!" << std::endl;
                break;
            }
            switchPlayer();
        }
    }
}

void TicTacToe::playAgainstAI() {
    int row, col;
    while (true) {
        if (currentPlayer == 1) {
            printBoardWithGraphics();
            std::cout << "Player X's turn. Enter row and column: ";
            std::cin >> row >> col;
            if (makeMove(row, col)) {
                if (checkWin()) {
                    printBoardWithGraphics();
                    std::cout << "Player X wins!" << std::endl;
                    break;
                }
                if (isBoardFull()) {
                    printBoardWithGraphics();
                    std::cout << "It's a draw!" << std::endl;
                    break;
                }
                switchPlayer();
            }
        } else {
            playEasyAI();
            if (checkWin()) {
                printBoardWithGraphics();
                std::cout << "Player O wins!" << std::endl;
                break;
            }
            if (isBoardFull()) {
                printBoardWithGraphics();
                std::cout << "It's a draw!" << std::endl;
                break;
            }
            switchPlayer();
        }
    }
}

void TicTacToe::playEasyAI() {
    int row, col;
    while (true) {
        row = rand() % 3 + 1; // Generate random row (1-3)
        col = rand() % 3 + 1; // Generate random column (1-3)
        if (makeMove(row, col))
            break;
    }
}
