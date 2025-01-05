class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            int sh = h - n;
            for (int p : piles) {
                if (p > mid) {
                    sh -= p / mid - 1;
                    if (p % mid)
                        sh -= 1;
                }
            }
            if (sh < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};