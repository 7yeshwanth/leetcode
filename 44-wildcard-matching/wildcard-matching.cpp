class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= ns; i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= np; j++) {
            bool fl = 1;
            for (int jj = 1; jj <= j; jj++) {
                if (p[jj - 1] != '*')
                    fl = 0;
            }
            dp[0][j] = fl;
        }
        for (int i = 1; i < ns + 1; i++) {
            for (int j = 1; j < np + 1; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[ns][np];
    }
};