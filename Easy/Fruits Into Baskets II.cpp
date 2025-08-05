class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); // تتبع السلال المستخدمة
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            bool placed = false;

            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;   // السلة دي بقت مستخدمة
                    placed = true;   // الفاكهة دي اتحطت
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
