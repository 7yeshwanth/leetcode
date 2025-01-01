class Solution {
public:
    map<char, int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int n = s.length()-1;
        int r = m[s[n]];
        n--;
        while (n >= 0) {
            if (m[s[n]] >= m[s[n+1]]) {
                r += m[s[n]];
            }
            else {
                r -= m[s[n]];
            }
            n--;
        }
        return r;
    }
};