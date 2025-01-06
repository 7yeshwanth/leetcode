bool u(string s, string p, int ns, int np, int is, int ip,
       vector<vector<int>>& dp) {
    if (is == ns && ip == np) {
        return 1;
    }
    if (is >= ns) {
        if (ip == np - 1 && p[ip] == '*')
            return 1;
        return 0;
    }
    if (ip >= np) {
        return 0;
    }
    if (dp[is][ip] == -1) {
        if (s[is] == p[ip] || p[ip] == '?') {
            dp[is][ip] = u(s, p, ns, np, is + 1, ip + 1, dp);
            return dp[is][ip];
        }
        if (p[ip] == '*') {
            dp[is][ip] = u(s, p, ns, np, is, ip + 1, dp) ||
                         u(s, p, ns, np, is + 1, ip, dp);
            return dp[is][ip];
        }
    } else
        return dp[is][ip];
    return 0;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        if (ns == np && ns == 0)
            return 1;
        string pp;
        pp += p[0];
        for (int i = 1; i < np; i++) {
            if (p[i] == '*' && pp.back() == p[i])
                continue;
            pp += p[i];
        }
        np = pp.size();
        vector<vector<int>> dp(ns, vector<int>(np, -1));
        return u(s, pp, ns, np, 0, 0, dp);
    }
};