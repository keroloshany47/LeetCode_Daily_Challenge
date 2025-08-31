
// this is leetcode solution i couldn't solve it 
class Solution {
    int n = 3, N = 9;
    int rows[9][10] = {}, cols[9][10] = {}, boxes[9][10] = {};
    vector<vector<char>>* boardPtr;
    bool sudokuSolved = false;

    bool couldPlace(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        return rows[row][d] + cols[col][d] + boxes[idx][d] == 0;
    }

    void placeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]++;
        cols[col][d]++;
        boxes[idx][d]++;
        (*boardPtr)[row][col] = d + '0';
    }

    void removeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        cols[col][d]--;
        boxes[idx][d]--;
        (*boardPtr)[row][col] = '.';
    }

    void placeNextNumbers(int row, int col) {
        if (row == N - 1 && col == N - 1) sudokuSolved = true;
        else if (col == N - 1) backtrack(row + 1, 0);
        else backtrack(row, col + 1);
    }

    void backtrack(int row, int col) {
        if ((*boardPtr)[row][col] == '.') {
            for (int d = 1; d <= 9; d++) {
                if (couldPlace(d, row, col)) {
                    placeNumber(d, row, col);
                    placeNextNumbers(row, col);
                    if (!sudokuSolved) removeNumber(d, row, col);
                }
            }
        } else placeNextNumbers(row, col);
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        boardPtr = &board;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] != '.') placeNumber(board[i][j] - '0', i, j);
        backtrack(0, 0);
    }
};





// this is Aai solution also 

class Solution {
public:
    // Function to check if we can place 'c' in board[row][col]
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c) return false;
            // Check column
            if (board[i][col] == c) return false;
            // Check 3x3 block
            int blockRow = 3 * (row / 3) + i / 3;
            int blockCol = 3 * (col / 3) + i % 3;
            if (board[blockRow][blockCol] == c) return false;
        }
        return true;
    }

    // Backtracking function to solve Sudoku
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') { // Empty cell
                    for (char c = '1'; c <= '9'; c++) { // Try digits 1-9
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place digit
                            if (solve(board)) return true; // Continue
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid digit found
                }
            }
        }
        return true; // Solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
