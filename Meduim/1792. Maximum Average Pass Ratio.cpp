class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calcGain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // max heap: {gain, pass, total}
        priority_queue<tuple<double,int,int>> pq;

        for (int i = 0; i < classes.size(); i++) {
            int pass = classes[i][0], total = classes[i][1];
            pq.push({calcGain(pass, total), pass, total});
        }

        while (extraStudents--) {
            auto [gain, pass, total] = pq.top();
            pq.pop();
            pass++;
            total++;
            pq.push({calcGain(pass, total), pass, total});
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto [gain, pass, total] = pq.top();
            pq.pop();
            sum += (double)pass / total;
        }

        return sum / classes.size();
    }
};
