#include <iostream>
#include <vector>
#include <iomanip>

class SudokuSolver {
public:
    SudokuSolver(std::vector<std::vector<int>> initialBoard) : board(initialBoard) {}

    bool solve() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == 0) {
                    for (int num = 1; num <= 9; num++) {
                        if (isValidMove(row, col, num)) {
                            board[row][col] = num;
                            if (solve()) {
                                return true;
                            }
                            board[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printBoard() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                std::cout << std::setw(2) << board[row][col] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> board;

    bool isValidMove(int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }

        int boxRow = 3 * (row / 3);
        int boxCol = 3 * (col / 3);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    std::vector<std::vector<int>> initialBoard = {
        {5, 0, 9, 0, 0, 0, 4, 0, 0},
        {7, 0, 8, 3, 0, 4, 9, 0, 0},
        {6, 0, 1, 0, 0, 0, 7, 3, 0},
        {4, 6, 2, 5, 0, 0, 0, 0, 0},
        {3, 8, 5, 7, 2, 0, 6, 4, 9},
        {1, 0, 7, 4, 0, 8, 2, 0, 0},
        {2, 0, 0, 1, 0, 0, 0, 0, 4},
        {0, 0, 3, 0, 4, 0, 0, 8, 7},
        {0, 7, 0, 0, 5, 3, 0, 0, 6}
    };

    SudokuSolver solver(initialBoard);
    if (solver.solve()) {
        std::cout << "Solved Sudoku:" << std::endl;
        solver.printBoard();
    } else {
        std::cout << "No solution!" << std::endl;
    }

    return 0;
}
