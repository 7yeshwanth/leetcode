class Solution {
public:
    int gv(vector<int>& arr, int i, int j) {
        return min(arr[i], arr[j]) * (j - i);
    }
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        int ar = gv(arr, i, j);
        while (i < j) {
            ar = max(ar, gv(arr, i, j));
            if (arr[i] < arr[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ar;
    }
};