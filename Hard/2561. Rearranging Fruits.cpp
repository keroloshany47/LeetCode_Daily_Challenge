// i couldnot solve this prblem so i search and ask claude so i can understand it 
//LeetCode: 2561. Rearranging Fruits
// Difficulty: Hard
// Link: https://leetcode.com/problems/rearranging-fruits/description/?envType=daily-question&envId=2025-08-02

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> diff;
        int minFruit = INT_MAX;
        
        // Calculate difference and find minimum in single pass
        for (int fruit : basket1) {
            diff[fruit]++;
            minFruit = min(minFruit, fruit);
        }
        for (int fruit : basket2) {
            diff[fruit]--;
            minFruit = min(minFruit, fruit);
        }
        
        // Collect fruits that need swapping
        vector<int> toSwap;
        toSwap.reserve(basket1.size()); // Reserve space to avoid reallocations
        
        for (auto& [fruit, count] : diff) {
            if (count % 2 != 0) {
                return -1; // Impossible if any fruit has odd difference
            }
            
            // Add half of excess fruits (we only need to consider half for swapping)
            int excess = abs(count) / 2;
            for (int i = 0; i < excess; i++) {
                toSwap.push_back(fruit);
            }
        }
        
        // Sort once - we only need the smaller half
        int n = toSwap.size();
        nth_element(toSwap.begin(), toSwap.begin() + n/2, toSwap.end());
        sort(toSwap.begin(), toSwap.begin() + n/2);
        
        long long totalCost = 0;
        long long doubleMinFruit = 2LL * minFruit;
        
        // Calculate cost for the cheaper half of swaps
        for (int i = 0; i < n/2; i++) {
            totalCost += min((long long)toSwap[i], doubleMinFruit);
        }
        
        return totalCost;
    }
};
/*
Algorithm Explanation:
1. Use difference counting: increment for basket1, decrement for basket2
2. Check feasibility: all differences must be even
3. Collect fruits needing swaps (only half of excess needed)
4. Use partial sorting to find cheaper half efficiently
5. For each cheap fruit, choose min(direct_cost, indirect_cost)

Key Optimizations:
- Single pass frequency calculation
- Partial sorting with nth_element
- Only process cheaper half of swaps
- Memory reservation to avoid reallocations

Time Complexity: O(n + k log k) where k ≤ n (swaps needed)
- O(n): Single pass through both baskets
- O(k): Collecting fruits to swap
- O(k + (k/2)log(k/2)): Partial sorting (nth_element + sort)
- O(k/2): Final cost calculation

Space Complexity: O(k) where k ≤ n
- O(unique_fruits): Hash map for differences
- O(k): Vector for fruits to swap
- Total: O(k) auxiliary space

Best Case: O(n) time when no swaps needed
Worst Case: O(n log n) time when all fruits need swapping
*/
