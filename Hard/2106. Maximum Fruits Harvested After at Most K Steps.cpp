// LeetCode: 2106. Maximum Fruits Harvested After at Most K Steps
// Difficulty: Hard
// Link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
// Topics: Sliding Window, Greedy, Prefix Sum, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(n) for storing prefix sums
// this is chat gpt solution i make him explain it to me because it hard for me to implement 
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, right = 0;
        int maxFruits = 0;
        int currentSum = 0;

        // Slide a window [left, right] over the fruit positions
        while (right < n) {
            int fruitPos = fruits[right][0];
            int fruitAmt = fruits[right][1];
            currentSum += fruitAmt;

            // Check if the current window is reachable within k steps
            while (left <= right && !canReach(fruits[left][0], fruitPos, startPos, k)) {
                currentSum -= fruits[left][1];
                left++;
            }

            maxFruits = max(maxFruits, currentSum);
            right++;
        }

        return maxFruits;
    }

private:
    // Check if the window from l to r is reachable from startPos within k steps
    bool canReach(int l, int r, int start, int k) {
        // Two ways to go: go left first, or go right first
        int leftThenRight = abs(start - l) + abs(r - l);
        int rightThenLeft = abs(start - r) + abs(r - l);
        return min(leftThenRight, rightThenLeft) <= k;
    }
};
