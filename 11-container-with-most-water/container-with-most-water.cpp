class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        int ar =min(arr[i], arr[j]) * (j - i);
        while (i < j) {
            ar = max(ar, min(arr[i], arr[j]) * (j - i));
            if (arr[i] < arr[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ar;
    }
};