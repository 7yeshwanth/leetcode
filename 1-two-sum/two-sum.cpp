class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if (m.find(x) != m.end()) {
                return {m[x], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};