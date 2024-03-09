#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    int currentPlayer; // 1 for player X, -1 for player O

public:
    TicTacToe();
    void printBoardWithGraphics();
    bool makeMove(int row, int col);
    bool checkWin();
    bool isBoardFull();
    void switchPlayer();
    void play();
    void playAgainstAI();
    void playEasyAI();
};

#endif
