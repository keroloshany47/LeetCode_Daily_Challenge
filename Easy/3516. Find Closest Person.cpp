class Solution {
public:
    int findClosest(int x, int y, int z) {
        int min_step = abs(x - z);

        if (min_step == abs(y - z)) {
            return 0; 
        } 
        else if (min_step < abs(y - z)) {
            return 1; 
        } 
        else {
            return 2; 
        }
    }
};
