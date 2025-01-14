class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % 2)
            return 0;
        sum /= 2;
        vector<bool> prev(sum + 1, 0);
        prev[0] = 1;
        if (nums[0] <= sum)
            prev[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++) {
            vector<bool> curr(sum + 1, 0);
            for (int j = 0; j < sum + 1; j++) {
                if (j < nums[i])
                    curr[j] = prev[j];
                else
                    curr[j] = prev[j] || prev[j - nums[i]];
            }
            prev = curr;
        }
        return prev[sum];
    }
};