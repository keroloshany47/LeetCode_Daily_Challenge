// AI solution 

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];
                if (ax <= bx && ay >= by && (i != j)) {
                    bool empty = true;
                    for (int k = 0; k < n && empty; ++k) {
                        if (k == i || k == j) continue;
                        int px = points[k][0], py = points[k][1];
                        if (ax <= px && px <= bx && by <= py && py <= ay) {
                            empty = false; 
                        }
                    }
                    if (empty) ++ans;
                }
            }
        }
        return ans;
    }
};
