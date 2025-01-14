class Solution {
public:
    int myAtoi(string s) {
        int n(s.size()), i(0);
        int ans(0);
        while (i < n && s[i] == ' ')
            i++;
        char sm = '+';
        if (s[i] == '-' || s[i] == '+') {
            sm = s[i];
            i++;
        }
        bool bf = 0;
        while (i < n) {
            int v = s[i] - '0';
            if (v < 0 || v > 9) {
                break;
            }
            if (ans * 10l + v > INT_MAX) {
                ans = INT_MAX;
                bf = 1;
                break;
            }
            ans = ans * 10 + v;
            i++;
        }
        cout << ans << endl;
        if (ans == INT_MAX && bf) {
            return (sm == '-') ? INT_MIN : ans;
        }
        return (sm == '-') ? -ans : ans;
    }
};