class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue;

                int num = val - '0';      
                int mask = 1 << (num - 1);

                int boxIndex = (r / 3) * 3 + (c / 3);

                
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIndex] & mask)) {
                    return false;
                }

                
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIndex] |= mask;
            }
        }
        return true;
    }
};
