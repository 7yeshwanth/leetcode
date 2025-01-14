class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        vector<bool> prev(np + 1, 0);
        prev[0] = 1;
        for (int j = 1; j <= np; j++) {
            bool fl = 1;
            for (int jj = 1; jj <= j; jj++) {
                if (p[jj - 1] != '*')
                    fl = 0;
            }
            prev[j] = fl;
        }
        for (int i = 1; i < ns + 1; i++) {
            vector<bool> cur(np + 1, 0);
            cur[0] = 0;
            for (int j = 1; j < np + 1; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    cur[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                    cur[j] = cur[j - 1] || prev[j];
                else
                    cur[j] = 0;
            }
            prev = cur;
        }
        return prev[np];
    }
};