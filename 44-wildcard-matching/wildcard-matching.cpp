class Solution
{
  bool u(string s, string p, int ns, int np, vector<vector<int>> &dp)
  {
    if (ns < 0 && np < 0)
    {
      return 1;
    }
    if (ns < 0)
    {
      if (np == 0 && p[0] == '*')
        return 1;
      return 0;
    }
    if (np < 0)
    {
      return 0;
    }
    if (dp[ns][np] == -1)
    {
      if (s[ns] == p[np] || p[np] == '?')
      {
        return dp[ns][np] = u(s, p, ns - 1, np - 1, dp);
      }
      if (p[np] == '*')
      {
        return dp[ns][np] = u(s, p, ns, np - 1, dp) ||
                            u(s, p, ns - 1, np, dp);
      }
    }
    else
      return dp[ns][np];
    return 0;
  };

public:
  bool isMatch(string s, string p)
  {
    int ns = s.size(), np = p.size();
    if (ns == np && ns == 0)
      return 1;
    string pp;
    pp += p[0];
    for (int i = 1; i < np; i++)
    {
      if (p[i] == '*' && pp.back() == p[i])
        continue;
      pp += p[i];
    }
    np = pp.size();
    vector<vector<int>> dp(ns, vector<int>(np, -1));
    return u(s, pp, ns - 1, np - 1, dp);
  }
};