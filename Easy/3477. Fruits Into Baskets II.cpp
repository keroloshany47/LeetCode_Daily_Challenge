// LeetCode: 3477. Fruits Into Baskets II
// Difficulty: Easy
// Link: https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// Where n = number of fruit types (and baskets)

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); 
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            bool placed = false;

            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;   
                    placed = true;  
                    break;
                }
            }

            if (!placed) {
                unplaced++; // الفاكهة دي ملقتش سلة
            }
        }

        return unplaced;
    }
};
