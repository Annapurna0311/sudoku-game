#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 9;

bool isSafe(int board[N][N], int row, int col, int num) {
    // Check if 'num' is already in the same row
    for (int i = 0; i < N; i++)
        if (board[row][i] == num)
            return false;

    // Check if 'num' is already in the same column
    for (int i = 0; i < N; i++)
        if (board[i][col] == num)
            return false;

    // Check if 'num' is already in the same 3x3 box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + boxRowStart][j + boxColStart] == num)
                return false;

    return true;
}

void printBoard(int grid[N][N]) {
    system("cls");
    cout << "\t\t\t<================================================================================>" << endl;
    cout << "\t\t\t|                        WELCOME TO SUDOKU Game!                                 |" << endl;
    cout << "\t\t\t|       Fill in the missing numbers (represented by 0) to solve the puzzle.       |" << endl;
    cout << "\t\t\t<================================================================================>" << endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        cout << endl;
        if (row == 2 || row == 5) {
            for (int i = 0; i < N; i++)
                cout << "---";
            cout << endl;
        }
    }
}

bool solveSudoku(int board[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

bool isSolvedCompletely(int grid[N][N]) {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return false;

    return true;
}

void playGame(int board[N][N]) {
    int row, col, num;
    while (true) {
        printBoard(board);
        cout << endl << endl;
        cout << "Unable to solve? Enter -1 for row, col, and num to view the solved Sudoku." << endl;
        cout << "Enter row (1-9): ";
        cin >> row;
        cout << "Enter column (1-9): ";
        cin >> col;
        cout << "Enter number (1-9): ";
        cin >> num;

        if (row == -1 || col == -1 || num == -1) {
            solveSudoku(board, 0, 0);
            printBoard(board);
            cout << "Better luck next time!!!" << endl;
            return;
        }

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        row--;
        col--;

        if (!isSafe(board, row, col, num)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = num;

        if (isSolvedCompletely(board)) {
            printBoard(board);
            cout << "Congratulations! You have solved the puzzle." << endl;
            return;
        }
    }
}

int main() {
    system("title Sudoku Game");
    system("color B0");

    int board[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    cout << "\t\t\t<================================================================================>" << endl;
    cout << "\t\t\t|                        WELCOME TO SUDOKU Game!                                 |" << endl;
    cout << "\t\t\t|       Fill in the missing numbers (represented by 0) to solve the puzzle.       |" << endl;
    cout << "\t\t\t<================================================================================>" << endl;

    while (true) {
        int choice;
        cout << endl << endl;
        cout << "\t\t[1] Play the Sudoku" << endl;
        cout << "\t\t[2] View the solved Sudoku" << endl;
        cout << "\t\t[3] Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playGame(board);
                break;
            case 2:
                if (solveSudoku(board, 0, 0)) {
                    cout << "Completely Solved Sudoku:" << endl;
                    printBoard(board);
                } else {
                    cout << "No solution found." << endl;
                }
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
