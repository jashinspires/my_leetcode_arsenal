class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int initial_energy = 0;
        int current_energy = 0;
        
        for (const auto& task : tasks) {
            if (current_energy < task[1]) {
                initial_energy += task[1] - current_energy;
                current_energy = task[1];
            }
            current_energy -= task[0];
        }
        
        return initial_energy;
    }
};