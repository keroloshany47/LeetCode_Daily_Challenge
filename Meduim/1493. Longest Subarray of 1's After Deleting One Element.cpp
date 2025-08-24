class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, res = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) 
                zeros++;

            // لو عدد الأصفار في النافذة > 1 لازم نرجع left
            while (zeros > 1) {
                if (nums[left] == 0) 
                    zeros--;
                left++;
            }

            // طول النافذة - 1 (لأن لازم نحذف عنصر واحد)
            res = max(res, right - left);
        }

        return res;
    }
};
