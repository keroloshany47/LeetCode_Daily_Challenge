class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;

           
            int tempA = a;
            bool hasZeroA = false;
            while (tempA > 0) {
                if (tempA % 10 == 0) {
                    hasZeroA = true;
                    break;
                }
                tempA /= 10;
            }

            
            int tempB = b;
            bool hasZeroB = false;
            while (tempB > 0) {
                if (tempB % 10 == 0) {
                    hasZeroB = true;
                    break;
                }
                tempB /= 10;
            }

            if (!hasZeroA && !hasZeroB) {
                return {a, b};
            }
        }
        return {};
    }
};
