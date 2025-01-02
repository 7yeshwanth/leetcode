class Solution {
public:
    bool isPalindrome(int x) {
        long r = 0, t = x;
        while (x != 0)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        if (r == t && r >= 0) {
            return 1;
        }
        return 0;
    }
};