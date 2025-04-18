#include <algorithm>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0)
            return;
        int n = nums.size();
        int i, p;
        for (int x = 0; x < __gcd(n, k); x++) {
            i = x;
            p = nums[x];
            do {
                i = (i + k) % n;
                int t = nums[i];
                nums[i] = p;
                p = t;
            } while (i != x);
        }
    }
};