
void util(int m, vector<string> &result, string s, int n, int o = 1, int c = 0)
{
    if (s.length() == m * 2)
    {
        result.push_back(s);
        return;
    }
    if (n < m && o < m)
    {
        util(m, result, s + "(", n + 1, o + 1, c);
    }
    if (n > 0 && c < m)
    {
        util(m, result, s + ")", n - 1, o, c + 1);
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        util(n, result, "(", 1);
        return result;
    }
};