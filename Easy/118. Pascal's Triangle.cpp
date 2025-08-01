//LeetCode:118. Pascal's Triangle
// Difficulty: Easy
//Link:https://leetcode.com/problems/pascals-triangle/?envType=daily-question&envId=2025-08-01
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
     vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); 
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// Where n = numRows
