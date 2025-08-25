class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        int i = 0, j = 0, dir = 0; // dir = 0 (up-right), dir = 1 (down-left)

        for (int k = 0; k < m * n; k++) {
            result.push_back(mat[i][j]);

            if (dir == 0) { // going up-right
                i--; j++;
                if (j >= n) { i += 2; j = n - 1; dir = 1; }
                else if (i < 0) { i = 0; dir = 1; }
            } 
            else { // going down-left
                i++; j--;
                if (i >= m) { j += 2; i = m - 1; dir = 0; }
                else if (j < 0) { j = 0; dir = 0; }
            }
        }
        return result;
    }
};
