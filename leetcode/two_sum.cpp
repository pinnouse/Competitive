class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differences; // <difference, index>
        // for (int i = 0; i < nums.size(); ++i) {
        //     for (int j = i+1; j < nums.size(); ++j) {
        //         if (i == j) continue;
        //         if (nums[i] + nums[j] == target) {
        //             return vector<int> {i, j};
        //         }
        //     }
        // }
        differences[target-nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            if (differences.find(n) == differences.end()) {
                differences[target-n] = i;
                continue;
            }
            return vector<int> {i, differences[n]};
        }
        return vector<int> {-1, -1};
    }
};