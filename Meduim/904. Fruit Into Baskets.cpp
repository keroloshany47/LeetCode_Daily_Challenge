class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // stores fruit type and its count
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++; // add current fruit to basket

            // If we have more than 2 types, shrink window from the left
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]); // remove fruit type if count becomes 0
                }
                ++left; // move the left boundary
            }

            // Update max fruits collected
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
