class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (auto& c : classes) {
            maxHeap.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto [g, p_t] = maxHeap.top();
            maxHeap.pop();
            int pass = p_t.first, total = p_t.second;
            ++pass, ++total;  
            maxHeap.push({gain(pass, total), {pass, total}});
        }

        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, p_t] = maxHeap.top();
            maxHeap.pop();
            totalRatio += (double)p_t.first / p_t.second;
        }

        return totalRatio / classes.size();
    }
};