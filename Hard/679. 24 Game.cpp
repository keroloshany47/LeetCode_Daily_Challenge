#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
    
private:
    const double EPS = 1e-6;
    
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double> next;
                
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                
                double a = nums[i], b = nums[j];
                
                vector<double> candidates = {a + b, a - b, b - a, a * b};
                if (fabs(b) > EPS) candidates.push_back(a / b);
                if (fabs(a) > EPS) candidates.push_back(b / a);
                
                for (double val : candidates) {
                    next.push_back(val);
                    if (dfs(next)) return true;
                    next.pop_back(); 
                }
            }
        }
        return false;
    }
};
